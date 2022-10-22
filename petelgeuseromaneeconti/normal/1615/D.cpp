#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int T,n,m;
bool err;
vector<tuple<int,int> >e[N];
struct ufs{
	int fa[N],dis[N];
	void init(int n){
		rep(i,1,n)fa[i]=i,dis[i]=0;
	}
	int fd(int k1){
		if(k1!=fa[k1]){
			int k2=fa[k1];
			fa[k1]=fd(fa[k1]);
			dis[k1]^=dis[k2];
		}
		return fa[k1];
	}
	void mer(int k1,int k2,int k3){
		int k1_=fd(k1),k2_=fd(k2);
		if(k1_!=k2_){
			fa[k1_]=k2_;
			dis[k1_]=dis[k1]^dis[k2]^k3;
		}else{
			if((dis[k1]^dis[k2])!=k3){
				err=1;
			}
		}
	}
}o;
void dfs1(int k1,int k2,int k3){
	if(k1!=1){
		if(k3==-1){
			o.fd(k1),o.fd(k2);
			printf("%d %d %d\n",k1,k2,o.dis[k1]^o.dis[k2]);
		}else{
			printf("%d %d %d\n",k1,k2,k3);
		}
	}
	for(auto&x:e[k1])if(get<0>(x)!=k2){
		dfs1(get<0>(x),k1,get<1>(x));
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		o.init(n);
		rep(i,1,n)e[i].clear();
		err=0;
		rep(i,2,n){
			int x,y,v;
			rd(x),rd(y),rd(v);
			if(v==-1){
				e[x].eb(y,-1),e[y].eb(x,-1);
			}else{
				e[x].eb(y,v),e[y].eb(x,v);
				o.mer(x,y,__builtin_popcount(v)&1);
			}
		}
		rep(i,1,m){
			int a,b,p;
			rd(a),rd(b),rd(p);
			o.mer(a,b,p);
		}
		if(err){
			puts("NO");
		}else{
			puts("YES");
			dfs1(1,0,0);
		}
	}
	return 0;
}