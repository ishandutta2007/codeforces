#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<int> a(3*n);
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
	for (int k = 2; k <= n; ++k)
	{
		int si = k - 2;
		if(n % k)
			a[n + si] = a[si + n - (n % k)];
		for (int i = n / k; i > 0 ; --i)
			a[si + k*i] = a[si + k*(i - 1)];
	}
	int si = n - 1;
	for (int i = si; i < si + n; ++i)
		cout << a[i] << " ";
}