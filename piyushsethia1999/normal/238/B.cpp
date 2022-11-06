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
	int n, h;
	cin >> n >> h;
	std::vector<std::pair<int, int> > a(n);
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a[i] = (mp(x, i));
	}
	if(n == 2)
	{
		cout << "0\n1 1";
		exit(0);
	}
	sort(a.begin(), a.end());
	print(a);
	std::vector<int> v(n, 1);
	if(((a[n-1].first + a[n-2].first) - (a[1].first + a[0].first)) > (max(a[n-1].first + a[n-2].first, a[n-1].first + a[0].first + h) - min(a[1].first + a[2].first, a[0].first + a[1].first + h)))
		v[a[0].second] = 2;
	cout << min(((a[n-1].first + a[n-2].first) - (a[1].first + a[0].first)), (max(a[n-1].first + a[n-2].first, a[n-1].first + a[0].first + h) - min(a[1].first + a[2].first, a[0].first + a[1].first + h))) << "\n";
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
}