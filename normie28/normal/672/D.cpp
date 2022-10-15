#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 5e5+51;
 
ll date[maxn];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n, k, i, tmp;
	cin>>n>>k;
	ll sum = 0;
	for (i=1; i<=n; ++i) {
	    cin>>date[i];
		sum += date[i];
	}
	sort(date+1, date+n+1);
	ll aver = (sum + n - 1) / n;
	ll ans1, left, right, mid;
	left = 0; right = sum / n;
	ll tsum;
	while (left <= right) {
		mid = (left + right) / 2;
		tsum = 0;
		for (i=1; i<=n; ++i) 
			if (mid >= date[i])
				tsum += mid - date[i];
		/*
		for (i=1; i<=n && mid>date[i]; ++i) 
			tsum += mid - date[i];
			*/
		if (tsum <= k) {
			ans1 = mid; 
			left = mid + 1;
		} else right = mid - 1;
	}
	ll ans2 = 0;
	left = aver; right = 0x3f3f3f3f;
	tsum = 0; 
	while (left <= right) {
		mid = (left + right) / 2;
		tsum = 0;
		for (i=1; i<=n; ++i) 
			if (mid <= date[i])
				tsum += date[i] - mid;
	/*	for (i=upper_bound(date+1,date+n+1, mid) - date; i<=n; ++i) 
			tsum += date[i] - mid;*/
		if (tsum <= k) {
			ans2 = mid; 
			right = mid - 1;
		} else left = mid + 1;
	}
	cout<<ans2-ans1;
	return 0;
}