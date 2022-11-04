#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3505;
int T, n, m, k, a[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &k), k=min(k, m-1);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		int ans=0;
		for(int i=0; i<=k; ++i){
			int mn=1e9;
			for(int j=0; j<=m-1-k; ++j)
				mn=min(mn, max(a[i+j+1], a[n-(m-1-i-j)]));
			ans=max(ans, mn);
		}
		printf("%d\n", ans);
	}
	return 0;
}