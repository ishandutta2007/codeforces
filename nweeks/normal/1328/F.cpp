#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	sort(arr.begin(), arr.end());
	vector<pair<ll, int> > compress;

	int l(0);
	while (l < n)
	{
		int r = l+1;
		while ( r < n and arr[l] == arr[r])
			++r;
		compress.emplace_back(arr[l], r-l);
		l=r;
	}

	n = SZ(compress);

	vector<ll> needed_left(n);
	vector<ll> prefix_left(n);
	vector<ll> needed_right(n);
	vector<ll> prefix_right(n);
	ll cumu(0);
	ll tot(0);
	for (int i(0); i < n; ++i)
	{
		needed_left[i] = tot * (-1 + compress[i].first) - cumu;
		tot += compress[i].second;
		prefix_left[i] = tot;
		cumu += compress[i].first * compress[i].second;
	}

	cumu = 0;
	tot = 0;
	for (int i(0); i < n; ++i)
	{
		needed_right[n-i-1] = -tot * (1+compress[n-i-1].first) + cumu;
		tot += compress[n-i-1].second;
		cumu += compress[n-i-1].first * compress[n-i-1].second;
		prefix_right[n-i-1] = tot;
	}	

	ll ans = 1e18;
	for (int i(0); i < n; ++i)
	{
		ll wanted(k - compress[i].second);
		if (wanted <= 0)
		{
			ans = 0;
			break;
		}
		// Only left
		ll to_left = (i? prefix_left[i-1] : 0);
		ll to_right = (i !=n-1 ? prefix_right[i+1] : 0);
		ll req_left = needed_left[i];
		ll req_right = needed_right[i];
		if (to_right + to_left < wanted) continue;
		
		
		if (to_left >= wanted)
			ans = min(ans, req_left + wanted );
		if (to_right >= wanted)
			ans = min(ans, req_right + wanted);
		
		if (to_left < wanted)
			ans = min(ans, req_left + req_right + to_left 
									+ (wanted - to_left));
		if (to_right < wanted)
			ans = min(ans, req_right + req_left + to_right 
									+ (wanted - to_right));
	}
	cout << ans << endl;
}