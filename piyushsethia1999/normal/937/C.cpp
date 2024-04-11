#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int k; cin >> k;
	int d; cin >> d;
	int t; cin >> t;
	int t1 = 0;
	int t2 = 0;
	if (k > d)
	{
		int te = (k / d + (k % d ? 1 : 0)) * d;

		t2 = d - (k % d ? k % d : d);
		t1 = te - t2;
	}
	else {
		t1 = k;
		t2 = d - k;
	}
	t *= 2;
	int ct = t1 * 2 + t2;
	int cnt = t / ct;

	int rem = t % ct;

	double extra = 0;

	if (rem < 2 * t1)
	{
		extra = ((double)rem) / 2.0;
	}
	else {
		extra = t1 + (rem - 2 * t1);
	}
	double tot = ((double)cnt) * ((double)(t1 + t2)) + extra;
	cout << tot;

}