#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=500005;
int n,m;
LL c[Maxn];
vector<int> G[Maxn];
LL Hs[Maxn];
map<LL,vector<int> > M;
void mian(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) G[i].clear();
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for (int i=0;i<m;i++){
		int u,v;u=read();v=read();
		G[u].pb(v);
	}
	for (int i=1;i<=n;i++) Hs[i]=0;
	for (int i=1;i<=n;i++){
		LL H=rand()*rand()*rand()+rand()+rand()*rand();
		for (int j=0;j<G[i].size();j++) Hs[G[i][j]]^=H;
	}
	M.clear();
	for (int i=1;i<=n;i++) M[Hs[i]].pb(i);
	LL ans=0;
	for (auto X:M){
		if (X.first==0) continue;
		vector<int> V=X.second;
		LL S=0;
		for (int j=0;j<V.size();j++) S+=c[V[j]];
		ans=__gcd(ans,S);
	}
	printf("%lld\n",ans);
}
int main(){
	srand(time(0));
	int t;
	scanf("%d",&t);
	while (t--){
		mian();
	}
}