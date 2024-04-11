#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, k, best=1, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	
	int num=a[0];
	int lb=0;
	ll sum=0;
	for (int rb=1; rb<n; ++rb) {
		sum+=1ll*(rb-lb)*(a[rb]-a[rb-1]);
		while (sum>k) {
			sum-=a[rb]-a[lb];
			lb++;
		}
		if (rb-lb+1>best) {
			best=rb-lb+1;
			num=a[rb];
		}
	}
	cout << best << ' ' << num;
	return 0;
}