#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll p2[1010101];

vector<pair<int, int> > g[101010];//mihin menee, mista lahtee
int p[101010][30];
int d[101010];

int yp[101010];
int ym[101010];
int ap[101010];
int am[101010];

int lca(int a, int b){
	if (a==b) return a;
	for (int i=19;i>=0;i--){
		if (d[a]>=d[b]+(1<<i)){
			a=p[a][i];
		}
		if (d[b]>=d[a]+(1<<i)){
			b=p[b][i];
		}
	}
	if (a==b) return a;
	for (int i=19;i>=0;i--){
		if (p[a][i]!=p[b][i]){
			a=p[a][i];
			b=p[b][i];
		}
	}
	if (a==b) return a;
	return p[a][0];
}

void dfs1(int x, int pp, int dd){
	p[x][0]=pp;
	d[x]=dd;
	for (int i=1;i<20;i++){
		p[x][i]=p[p[x][i-1]][i-1];
	}
	for (auto nx:g[x]){
		if (nx.F!=pp){
			dfs1(nx.F, x, dd+1);
		}
	}
}

ll v=0;

pair<int, int> dfs2(int x, int pp){
	int ta=0;
	int ty=0;
	for (auto nx:g[x]){
		if (nx.F!=pp){
			auto asd=dfs2(nx.F, x);
			if (nx.S==x){
				v+=p2[asd.F];
			}
			if (nx.S==nx.F){
				v+=p2[asd.S];
			}
			v%=mod;
			ta+=asd.F;
			ty+=asd.S;
		}
	}
	ta+=ap[x];
	ty+=yp[x];
	ta-=am[x];
	ty-=ym[x];
	return {ta, ty};
}

int s[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	p2[1]=1;
	for (int i=2;i<1010101;i++){
		p2[i]=p2[i-1]*2ll;
		p2[i]%=mod;
	}
	for (int i=2;i<1010101;i++){
		p2[i]+=p2[i-1];
		p2[i]%=mod;
	}
	int n;
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a,b,x;
		cin>>a>>b>>x;
		if (x==0){
			g[a].push_back({b, -1});
			g[b].push_back({a, -1});
		}
		else{
			g[a].push_back({b, a});
			g[b].push_back({a, a});
		}
	}
	dfs1(1, 0, 1);
	int k;
	cin>>k;
	s[0]=1;
	for (int i=1;i<=k;i++){
		cin>>s[i];
	}
	for (int i=0;i<k;i++){
		int l=lca(s[i], s[i+1]);
		ap[s[i]]++;
		am[l]++;
		yp[s[i+1]]++;
		ym[l]++;
	}
	dfs2(1, 0);
	cout<<v<<endl;
}