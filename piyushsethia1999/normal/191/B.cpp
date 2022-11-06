#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n, k, b;
	cin >> n >> k >> b;
	std::vector<ll> a(n);
	std::vector<int> in(n-1);
	for (int i = 0; i < n-1; ++i) {
		cin >> a[i];
		in[i] = i;
	}
	cin >> a[n-1];
	sort(in.begin(), in.end(), [&](int i, int j)->bool{return (a[i] > a[j]);});
	print(in);
	int km1 = 0;
	for (int i = 0; i < k-1; ++i)
		km1 += a[in[i]];
	int tk = km1 + a[in[k-1]];
	for (int i = 0; i < n-1; ++i)
		if( (((a[i] > a[in[k-1]]) ? (tk - a[i]) : (km1)) + a[i]) > b ) {
			cout << i+1;
			exit(0);
		}
	cout << n;
}