#include <bits/stdc++.h>
const int N=1e5+1;
int a[N], b[N];
long long s[N], min[20][N], max[20][N];
long long query_min(int l, int r) {
	int lv=31^__builtin_clz(r-l+1);
	return std::min(min[lv][l+(1<<lv)-1], min[lv][r]);
}
long long query_max(int l, int r) {
	int lv=31^__builtin_clz(r-l+1);
	return std::max(max[lv][l+(1<<lv)-1], max[lv][r]);
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	for(int i=0; i<n; ++i) scanf("%d", &b[i]);
	for(int i=0; i<n; ++i) s[i+1]=s[i]-a[i]+b[i];
	for(int i=1; i<=n; ++i) min[0][i]=max[0][i]=s[i];
	for(int i=0; (2<<i)<=n; ++i) {
		for(int j=(2<<i); j<=n; ++j) {
			min[i+1][j]=std::min(min[i][j-(1<<i)], min[i][j]);
			max[i+1][j]=std::max(max[i][j-(1<<i)], max[i][j]);
		}
	}
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(query_min(l, r)<s[l-1] || s[r]!=s[l-1]) {
			puts("-1");
		} else {
			printf("%lld\n", query_max(l, r)-s[l-1]);
		}
	}
	return 0;
}