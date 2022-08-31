#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int T, n, a[N], ans;
ll sum;
map<ll, int> mp;
int main() {
	scanf("%d", &n);
	mp[0] = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		if(mp[sum]) ans ++, mp.clear(), mp[0] = 1, sum = a[i];
		mp[sum] = 1;
	}
	printf("%d\n", ans);
	return 0;
}