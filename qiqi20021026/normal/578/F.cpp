#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
#define N 205
#define P(x,y) make_pair(x,y)

LL n,m,p,a[N][N],fa[N*N],mod,num[N*N],g[N][N],ans;
vector<pii> q1,q2;
char s[N][N];

LL gfa(LL x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}

void upd(LL &x,LL y){x=(x+y)%mod;}

void solve(){
	for (LL i=1;i<=p;++i) fa[i]=i;
	for (auto i:q1){
		LL x=i.first,y=i.second;
		x=gfa(x); y=gfa(y);
		if (x==y) return;
		fa[x]=y;
	}
	LL w=0;
	memset(num,0,sizeof num);
	for (LL i=1;i<=p;++i)
		if (fa[i]==i) num[i]=++w;
	if (w>201) return;
	memset(g,0,sizeof g);
	for (auto i:q2){
		LL x=i.first,y=i.second;
		x=gfa(x); y=gfa(y);
		++g[num[x]][num[y]];
		++g[num[y]][num[x]];
	}
	for (LL i=1;i<=w;++i){
		g[i][i]=0;
		for (LL j=1;j<=w;++j)
			if (i!=j){
				g[i][i]+=g[i][j];
				g[i][j]*=-1;
			}
	}
	LL sum=1;
	for (LL i=1;i<w;++i){
		for (LL j=i+1;j<w;++j)
			while (g[j][i]){
				swap(g[j],g[i]);
				sum*=-1;
				LL t=g[j][i]/g[i][i];
				for (LL k=i;k<w;++k){
					upd(g[j][k],-g[i][k]*t);
				}
			}
		sum=sum*g[i][i]%mod;
	}
	upd(ans,sum);
}

void ins(){
	q1.clear(); q2.clear();
	for (LL i=1;i<=n;++i){
		for (LL j=1;j<=m;++j){
			if (s[i][j]=='/'){
				LL x=a[i-1][j],y=a[i][j-1];
				if (x&&y) q1.push_back(P(x,y));
			}
			if (s[i][j]=='\\'){
				LL x=a[i-1][j-1],y=a[i][j];
				if (x&&y) q1.push_back(P(x,y));
			}
			if (s[i][j]=='*'){
				LL x=a[i-1][j],y=a[i][j-1];
				if (x&&y) q2.push_back(P(x,y));
				x=a[i-1][j-1],y=a[i][j];
				if (x&&y) q2.push_back(P(x,y));
			}
		}
	}
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&mod);
	for (LL i=1;i<=n;++i) scanf("%s",s[i]+1);
	for (LL i=0;i<=n;++i)
		for (LL j=0;j<=m;++j)
			if ((i+j)%2==0) a[i][j]=++p;
	ins(); solve();
	memset(a,0,sizeof a); p=0;
	for (LL i=0;i<=n;++i)
		for (LL j=0;j<=m;++j)
			if ((i+j)%2==1) a[i][j]=++p;
	ins(); solve();
	printf("%lld\n",(ans+mod)%mod);
	
	return 0;
}