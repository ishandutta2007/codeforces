#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int P=13;
const int mod=1e9+7;
const int N=1e6+5;
int n,m,ans,nod;
char sta[N],str[N];
int dep[N],fa[N][20],val[N];
int st[N],ed[N];
ll sum[N],pw[N],res;
vi edge[N],e[N];
 
int jump(int x,int p) {
	per(i,20,0) if ((p>>i)&1) x=fa[x][i];
	return x;
}
void dfs(int u,int f) {
	fa[u][0]=f; sum[u]=(sum[f]*P%mod+val[u])%mod;
	rep(i,1,20) fa[u][i]=fa[fa[u][i-1]][i-1];
	int fe=jump(u,m);
	//debug(fe);
	if (fe) {
		ll tmp=sum[u]-sum[fe]*pw[m]%mod;
		tmp=(tmp%mod+mod)%mod;
		//bug(res),debug(tmp);
		if (tmp==res) ans++;
	}
	rep(i,0,SZ(edge[u])) {
		int v=edge[u][i];
		dfs(v,u);
	}
}
 
int main() {
	pw[0]=1;
	rep(i,1,N) pw[i]=pw[i-1]*P%mod;
	scanf("%d",&n);
	nod++; ed[1]=1; val[1]=0;
	rep(i,2,n+1) {
		int f,len;
		scanf("%d%s",&f,str+1);
		len=strlen(str+1);
		e[f].pb(i); st[i]=nod+1;
		rep(j,1,len+1) {
			nod++; val[nod]=str[j];
			if (j!=1) edge[nod-1].pb(nod);
		}
		ed[i]=nod;
		//bug(i),bug(st[i]),debug(ed[i]);
	}
	rep(x,1,n+1) {
		rep(i,0,SZ(e[x])) {
			int y=e[x][i];
			edge[ed[x]].pb(st[y]);
		}	
	}
	scanf("%s",sta+1);
	m=strlen(sta+1);
	rep(i,1,m+1) res=(res*P+sta[i])%mod;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}