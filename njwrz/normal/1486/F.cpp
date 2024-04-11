/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n;
V<int> v[300005]; 
struct LCA{
	int to[300005][19],d[300005];
	int lca(int x,int y){
		if(d[x]<d[y])swap(x,y);
		int t=d[x]-d[y];
		rep(i,0,19){
			if(t&(1<<i))x=to[x][i];
		} 
		if(x==y)RE x;
		for(int i=18;i>=0;i--){
			if(to[x][i]!=to[y][i]){
				x=to[x][i];
				y=to[y][i];
			}
		}
		RE to[x][0];
	}
	int getdis(int x,int y){
		int dis=0;
		if(d[x]<d[y])swap(x,y);
		int t=d[x]-d[y];
		rep(i,0,19){
			if(t&(1<<i))x=to[x][i],dis+=(1<<i);
		} 
		if(x==y)RE dis;
		for(int i=18;i>=0;i--){
			if(to[x][i]!=to[y][i]){
				x=to[x][i];dis+=(1<<(i+1));
				y=to[y][i];
			}
		}
		dis+=2;
		RE dis;
	}
	void dfs(int x){
		for(auto u:v[x])if(u!=to[x][0]){
			to[u][0]=x;d[u]=d[x]+1;
			dfs(u);
		}
	}
	int get(int x,int y){
		rep(i,0,19){
			if(y&(1<<i)){
				x=to[x][i];
			}
		}
		RE x;
	}
	void init(){
		dfs(1);
		rep(i,1,19){
			FOR(j,1,n){
				to[j][i]=to[to[j][i-1]][i-1];
			}
		}
	}
}L;
class bit{
	public:
	int s[300005];
	void up(int p,int x){
		while(p<=n){
			s[p]+=x;
			p+=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p){
			re=re+s[p];
			p-=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
V<int> q[300005],lp[300005];
V<P<int,int> > qu[300005];
int num[300005],cnt,ans,sum[300005],l[300005],r[300005],pans[300005],sum2[300005];
void dfs(int x,int fa){
	num[x]=l[x]=++cnt;
	for(auto u:v[x])if(u!=fa){
		dfs(u,x);
	}
	r[x]=cnt;
}
void dfs2(int x,int fa){
	for(auto u:q[x]){
		tree.up(u,1);
	}
	for(auto u:v[x])if(u!=fa){
		dfs2(u,x);
	}
	int now=0;
	int len=qu[x].size();
	now=len+tree.get(r[x])-tree.get(l[x]-1);
	//tree 
	//qu lcax  
	//lp x 
	ans+=pans[x]*(now+lp[x].size());//12-4 
	for(auto u:qu[x]){
		sum[u.F]++;
		sum[u.S]++;
	}
	int add1;
	for(auto u:lp[x])sum2[u]++;
	add1=0;
	for(auto u:v[x])if(u!=fa){
		int tp=tree.get(r[u])-tree.get(l[u]-1);
		ans+=tp*(len-sum[u]);//23 
		ans+=sum2[u]*(tree.get(r[x])-tree.get(l[x]-1)-tp);//24 
		ans+=(len-sum[u])*sum2[u];add1+=(lp[x].size()-sum2[u])*sum2[u];
	}
	ans+=add1/2;
	add1=0;
	ans+=pans[x]*(pans[x]-1)/2;
	ans+=(tree.get(l[x])-tree.get(l[x]-1))*(len);
	map<P<int,int> ,int> mp;
	for(auto u:qu[x]){
		mp[u]++;
	}
	for(auto u:mp){
		add1+=(len-sum[u.F.F]-sum[u.F.S]+u.S)*u.S;
	}
	ans+=add1/2;
//	cout<<x<<' '<<ans<<'\n';
	for(auto u:qu[x]){
		sum[u.F]--;
		sum[u.S]--;
	}
	for(auto u:q[x]){
		tree.up(u,-1);
	}
	for(auto u:lp[x])sum2[u]--;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	L.init();
	dfs(1,-1);
	int m;
	cin>>m;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		if(x==y){
			pans[x]++;continue;
		}
		int l=L.lca(x,y);
		int to1,to2;
		if(l!=x){
			int d=L.getdis(x,l)-1;
			to1=L.get(x,d);
			q[to1].PB(num[x]); 
		}
		if(l!=y){
			int d=L.getdis(y,l)-1;
			to2=L.get(y,d);
			q[to2].PB(num[y]); 
		}
		if(l!=x&&l!=y){
			if(to1>to2)swap(to1,to2);
			qu[l].PB(MP(to1,to2));
		}
		if(l==x){
			lp[x].PB(to2);
		}
		if(l==y){
			lp[y].PB(to1);
		}
	}
	dfs2(1,-1);
	cout<<ans;
	RE 0;
}