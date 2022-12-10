#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e5 + 85 - 69;
LL a[maxn], por[maxn], porv[maxn];
LL n, k, x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> x;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
		por[i] = por[i - 1] | a[i - 1];
	for(int i = n - 2; i >= 0; i--)
		porv[i] = porv[i + 1] | a[i + 1];
	LL ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++)
			a[i] *= x;
		ans = max(ans, a[i] | por[i] | porv[i]);
	}
	cout << ans << endl;
	return 0;
}