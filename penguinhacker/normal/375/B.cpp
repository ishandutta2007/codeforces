#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000;
int n, m, cnt[mxN][mxN+1];
static char s[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	scanf("%d%d", &n, &m);
	for (int rep=0; rep<n; ++rep) {
		scanf("%s", s);
		for (int i=0; i<m;) {
			if (s[i]=='0') {
				++i;
				continue;
			}
			int j=i;
			while(j<m&&s[j]=='1')
				++j;
			for (int k=i; k<j; ++k)
				++cnt[k][j-k];
			i=j;
		}
	}
	int ans=0;
	for (int i=0; i<m; ++i) {
		int cur=0;
		for (int j=m; ~j; --j) {
			cur+=cnt[i][j];
			ans=max(ans, cur*j);
		}
	}
	printf("%d", ans);
	return 0;
}