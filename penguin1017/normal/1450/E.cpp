#include<bits/stdc++.h>
//#undef _GLIBCXX_HAVE_ICONV
//#include<bits/extc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
//using namespace __gnu_pbds;
const int N=1<<21;
const int mod=998244353;
const int inf=1e9;
/*
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int jie[N],inv[N];
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
*/
int f[210][210];
vi g[N];
int vis[210],c[210];
void dfs(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v])c[v]=c[u]^1,dfs(v);
		else{
			if(c[u]==c[v]){
				puts("NO");
				exit(0);
			}
		}
	}
}
int main(){
	//pre();
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,210)rep(j,0,210)f[i][j]=inf;
	rep(i,0,m){
		int u,v,op;
		scanf("%d%d%d",&u,&v,&op);
		g[u].pb(v);
		g[v].pb(u);
		f[u][v]=1;
		if(op==1)f[v][u]=-1;
		else f[v][u]=1;
	}
	rep(i,1,n+1){
		f[i][i]=0;
		if(!vis[i])dfs(i);
	} 
//	cout<<"ok\n";
	rep(k,1,n+1){
		rep(i,1,n+1)rep(j,1,n+1)f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	}
	int ans=0;
	int pos;
	rep(i,1,n+1){
		if(f[i][i]<0){
			puts("NO");
			exit(0);
		}
		int maxn=-inf,mini=inf;
		rep(j,1,n+1){
			maxn=max(maxn,f[i][j]);
			mini=min(mini,f[i][j]);
		}
		if(ans<=maxn-mini){
			ans=maxn-mini;
			pos=i;
		}
	}
	puts("YES");
	printf("%d\n",ans);
	rep(i,1,n+1)printf("%d ",f[pos][i]+n+n);
	
}