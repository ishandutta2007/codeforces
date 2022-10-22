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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int dp[55][55][55],dp2[55][55][55];
int n,s;
int siz[55];
V<P<int,int> > v[55]; 
int nowsiz;
int fa[55];
void getsiz(int x,int y){
	for(auto u:v[x])if(u.F!=y){
		getsiz(u.F,x);
		siz[x]+=siz[u.F];
	}
}
int val[55],to[55],tofa[55];
void dfs(int x,int y){
	bool f=0;
	for(auto u:v[x])if(u.F!=y){
		f=1;
		fa[u.F]=x;tofa[u.F]=u.S;
		dfs(u.F,x);
	}
	if(!f){
		FOR(i,0,nowsiz)dp[nowsiz][x][i]=((nowsiz-i>0)?tofa[x]:0)+dp2[nowsiz-i][x][nowsiz-i];
		dp[nowsiz][x][0]=1e18;
		RE;
	}
	FOR(i,0,nowsiz)val[i]=0;
	val[0]=1e18;
	for(auto u:v[x])if(u.F!=y){
		FOR(i,0,nowsiz)to[i]=0;
		to[0]=1e18;
		FOR(i,0,nowsiz)FOR(j,0,nowsiz-i)gmax(to[i+j],min(val[i],dp[nowsiz][u.F][j]+u.S));
		FOR(i,0,nowsiz)val[i]=to[i];
	}
	dp[nowsiz][x][0]=1e18;
	FOR(i,1,nowsiz)dp[nowsiz][x][i]=val[i];
}
void dfs2(int x,int y){
	for(auto u:v[x])if(u.F!=y){
		FOR(i,0,nowsiz)val[i]=dp2[nowsiz][x][i]+tofa[x];
		for(auto tu:v[x])if(tu.F!=y&&tu!=u){
			FOR(i,0,nowsiz)to[i]=0;
			to[0]=1e18;
			FOR(i,0,nowsiz)FOR(j,0,nowsiz-i)gmax(to[i+j],min(val[i],dp[nowsiz][tu.F][j]+tu.S));
			FOR(i,0,nowsiz)val[i]=to[i];
		}
		FOR(i,0,nowsiz)dp2[nowsiz][u.F][i]=val[i];
		dp2[nowsiz][u.F][0]=1e18;
	}
	dp2[nowsiz][x][0]=1e18;
	for(auto u:v[x])if(u.F!=y)dfs2(u.F,x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ed=0;
	FOR(i,2,n){
		int x,y,z;cin>>x>>y>>z;ed=z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	int t;
	cin>>s;
	cin>>t;
	FOR(i,1,t){
		int x;
		cin>>x;
		siz[x]++;
	}
	siz[s]=0;
	int rt=-1;
	if(n==1){
		cout<<0;
		RE 0;
	}else if(n==2){
		if(siz[1]||siz[2]){
			cout<<ed;
		}else cout<<0;
		RE 0;
	}
	FOR(i,1,n)if(v[i].size()>1)rt=i;
	FOR(i,1,t)FOR(j,1,n)FOR(k,0,t){
		dp[i][j][k]=dp2[i][j][k]=1e18;
	}
	FOR(i,1,t){
		nowsiz=i;
		dfs(rt,-1);
		FOR(j,0,t)dp2[nowsiz][rt][j]=0;
		dp2[nowsiz][rt][0]=1e18; 
		dfs2(rt,-1);
	}
	getsiz(s,-1);
	int ans=1e18;
//	cout<<dp[10][1][10]<<' ';
	for(auto u:v[s]){
		if(u.F==fa[s]){
			gmin(ans,dp2[t][s][siz[u.F]]+u.S);
		}else gmin(ans,dp[t][u.F][siz[u.F]]+u.S);
	}
	if(ans==(int)(1e18)){
		cout<<"Terrorists win";
	}else cout<<ans;
	RE 0;
}