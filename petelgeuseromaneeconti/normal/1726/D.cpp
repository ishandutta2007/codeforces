#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
class dsu{
public:
	int n;
	vector<int>fa;
	vector<int>sz;
	dsu(){}
	dsu(int n_):n(n_),fa(n_),sz(n_,1){
		iota(fa.begin(),fa.end(),0);
	}
	void assign(int n_){
		*this=dsu(n_);
	}
	int find(int u){
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	bool check(int u,int v){
		return find(u)==find(v);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			if(sz[v_]<sz[u_]){
				int tmp=u_;
				u_=v_;
				v_=tmp;
			}
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}
		return 0;
	}
};
class dsu_cycle:public dsu{
public:
	vector<int>vis;
	dsu_cycle(){}
	dsu_cycle(int n):dsu(n),vis(n){}
	void assign(int n_){
		*this=dsu_cycle(n_);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			if(vis[u_]&&vis[v_]){
				return 0;
			}
			if(sz[v_]<sz[u_]){
				int tmp=u_;
				u_=v_;
				v_=tmp;
			}
			vis[v_]|=vis[u_];
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}else{
			if(vis[u_]){
				return 0;
			}else{
				vis[u_]=1;
				return 1;
			}
		}
	}
};
const int N=200005;
int T,n,m,dep[N],ans[N],eu[N],ev[N];
bool vis[N];
vector<pair<int,int> >e[N];
int cnt;
void dfs1(int k1,int k2){
	vis[k1]=1;
	dep[k1]=dep[k2]+1;
	each(x,e[k1])if(x.first!=k2){
		if(!vis[x.first]){
			ans[x.second]=dep[k1]&1;
			dfs1(x.first,k1);
		}else if(dep[x.first]<dep[k1]){
			ans[x.second]=dep[k1]&1;
		}
	}
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)e[i].clear();
		rep(i,1,m){
			int u,v;
			rd(u),rd(v);
			e[u].eb(v,i);
			e[v].eb(u,i);
			eu[i]=u,ev[i]=v;
		}
		while(1){
			rep(i,1,m)ans[i]=0;
			rep(i,1,m){
				ans[i]=rng()&1;
			}
			dsu o1(n+1),o2(n+1);
			bool err=0;
			rep(i,1,m){
				if(ans[i]){
					if(!o1.unite(eu[i],ev[i])){
						err=1;
						break;
					}
				}else{
					if(!o2.unite(eu[i],ev[i])){
						err=1;
						break;
					}
				}
			}
			if(!err){
				rep(i,1,m)putchar(ans[i]+48);
				puts("");
				break;
			}
		}
	}
	return 0;
}