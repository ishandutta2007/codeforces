#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5123;
int a[maxn];
int table[maxn][maxn], n, ans[maxn][maxn];
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		table[i][i]=a[i];
		ans[i][i]=a[i];
	}
	int diff=1;
	while(diff<n){
		int upp=n-diff;
		for(int i=1; i<=upp; i++){
			table[i][i+diff]=table[i][i+diff-1]^table[i+1][i+diff];
			ans[i][i+diff]=max(max(table[i][i+diff], ans[i][i+diff-1]), ans[i+1][i+diff]);
		}
		diff++;
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", ans[l][r]);
	}
	return 0;
}