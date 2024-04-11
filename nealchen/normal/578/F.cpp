#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
int mod, fa[10201], id[10201], a[201][201];
char s[100][101];
int find(int u) {return (u==fa[u])?u:(fa[u]=find(fa[u]));}
long long power(long long a, int b) {
	long long ans=1;
	for(; b; a=a*a%mod, b>>=1) if(b&1) ans=ans*a%mod;
	return ans;
}
int main() {
	int n, m, e=0, ans=0;
	assert(scanf("%d%d%d", &n, &m, &mod)==3);
	for(int i=0; i<n; ++i) assert(scanf("%s", s[i])==1);
	for(int i=0; i<(n+1)*(m+1); ++i) fa[i]=i;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(s[i][j]!='*') {
				int u=i*(m+1)+j+(s[i][j]=='/'), v=(i+1)*(m+1)+j+(s[i][j]=='\\');
				if(find(u)==find(v)) {
					puts("0");
					return 0;
				}
				fa[find(u)]=find(v);
			} else ++e;
	for(int type=0; type<2; ++type) {
		int c=0;
		for(int i=0; i<=n; ++i)
			for(int j=0; j<=m; ++j)
				if((i+j)%2==type) {
					int u=i*(m+1)+j;
					if(fa[u]==u) id[u]=c++;
				}
		if(c<=e+1) {
			long long det=1;
			for(int i=0; i<c; ++i) memset(a[i], 0, c*sizeof(int));
			for(int i=0; i<n; ++i)
				for(int j=0; j<m; ++j)
					if(s[i][j]=='*') {
						int u=i*(m+1)+j, v=(i+1)*(m+1)+j;
						if((i+j)%2!=type) ++u; else ++v;
						u=id[find(u)], v=id[find(v)];
						if(u!=v) --a[u][v], --a[v][u], ++a[u][u], ++a[v][v];
					}
			for(int i=0; i<c; ++i)
				for(int j=0; j<c; ++j)
					if(a[i][j]<0) a[i][j]+=mod;
			for(int i=1; i<c; ++i) {
				int j=i;
				long long inv;
				while(j<c&&a[j][i]==0) ++j;
				if(j==c) {
					det=0;
					break;
				}
				if(i!=j) {
					for(int k=i; k<c; ++k) std::swap(a[i][k], a[j][k]);
					if(det) det=mod-det;
				}
				inv=power(a[i][i], mod-2);
				det=det*a[i][i]%mod;
				while(++j<c) {
					long long sca=(mod-a[j][i])*inv%mod;
					for(int k=i; k<c; ++k) a[j][k]=(sca*a[i][k]+a[j][k])%mod;
				}
			}
			ans=(ans+det)%mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}