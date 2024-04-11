#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 5005, M = 700;
ll ans;
int n, m, cnt, p[M], a[N], f[N][M];
pair<int,int> g1[N], g2[N], g3[N];
int main() {
	scanf("%d", &n);
	for(int i=0, x; i<n; ++i) scanf("%d", &x), ++a[x=max(x, 1)], m=max(m, x);
	for(int i=2; i<=m; ++i){
		for(int j=1; j<=cnt; ++j) if(i%p[j]==0) goto skip;
		p[++cnt]=i;
		skip:;
	}
	for(int i=1; i<=m; ++i){
		memcpy(f[i], f[i-1], M<<2);
		for(int j=1, x=i; j<=cnt; ++j)
			while(x%p[j]==0) x/=p[j], ++f[i][j], f[i][0]=max(f[i][0], j);
	}
	for(int i=1; i<=m; ++i){
		int c1=0, c2=0;
		for(int j=i-1; j; --j){
			int k=max(f[i][0], f[j][0]), tot=0;
			while(f[i][k]==f[j][k]) tot+=f[i][k], --k;
			g1[++c1]=make_pair(tot+min(f[i][k], f[j][k]), a[j]);
		}
		for(int j=i; j<=m; ++j){
			int k=max(f[i][0], f[j][0]), tot=0;
			while(f[i][k]==f[j][k] && k>1) tot+=f[i][k], --k;
			g2[++c2]=make_pair(tot+min(f[i][k], f[j][k]), a[j]);
			// if(i==3) printf("shit: %d\n", k);
		}
		int c3=0;
		while(c1 || c2)
			if(c1 && (g1[c1]<g2[c2] || !c2)) g3[++c3]=g1[c1--];
			else g3[++c3]=g2[c2--];
		ll now=0;
		for(int j=1, rest=n; j<=m; ++j){
			now+=(ll)g3[j].second*g3[j].first, rest-=g3[j].second;
			ans=min(ans, (ll)g3[j].first*(n-2*rest)-2*now);
			// printf(">> %d %d %d %lld\n", i, g3[j].first, g3[j].second, now);
		}
	}
	for(int i=1; i<=m; ++i) for(int j=1; j<=cnt; ++j) ans+=(ll)a[i]*f[i][j];
	printf("%lld\n", ans);
	return 0;
}