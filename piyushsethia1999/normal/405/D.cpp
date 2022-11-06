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
	int N = 1000000;
	int n;
	cin >> n;
	std::vector<bool> a(N+1, false);
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a[x] = true;
	}
	std::vector<int> nbu;
	std::vector<int> comp;
	for (int i = 1; i <= ((N)/2); ++i)
	{
		if(a[i]&&(!a[N-i+1])) {
			comp.pb(N-i+1);
		}
		else if((!a[i])&&a[N-i+1]) {
			comp.pb(i);
		}
		else if((!a[i])&&(!a[N-i+1])) {
			nbu.pb(i);
			nbu.pb(N-i+1);
		}
	}
	print(comp.size());
	cout << n << '\n';
	for (int i = 0; i < comp.size(); ++i)
		cout << comp[i] << ' ';
	for (int i = 0; i < (n-comp.size()); ++i)
		cout << nbu[i] << ' ';
}