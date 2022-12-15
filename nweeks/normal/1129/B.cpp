#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll k;
	cin >> k;

	for (int n(1); n <= 2000; ++n)
	{
		ll S = n+k;

		vector<ll> arr(n-1);

		bool ok  = true;
		for (int i(0); i < SZ(arr); ++i)
		{
			ll take = min((ll)1e6, S-(SZ(arr)-(i+1)));
			S -= take;
			arr[i]=take;
			if (take<0) ok=false;
		}
		if (S > 0) ok = false;
		if (ok)
		{
			cout << n << endl;
			cout << -1 << ' ';
			for (auto v : arr)
				cout << v << ' ';
			cout << endl;
			return 0;
		}
	}
	cout <<-1 << endl;
}