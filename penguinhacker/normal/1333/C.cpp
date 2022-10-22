#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, lb=-1, a[200000];
map<ll, int> mp;
ll ans=0, sum=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	mp[0]=-1;
	for (int i=0; i<n; ++i) {
		sum+=a[i];
		if (mp.find(sum)!=mp.end()&&mp[sum]>=lb) {
			lb=mp[sum]+1;
		}
		mp[sum]=i;
		ans+=i-lb;
	}
	cout << ans;
	return 0;
}