#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	ll v[2][2] = {0};
	for (int i = 0; i < n; ++i)
	{
		v[a[i] - '0'][b[i] - '0']++;
	}
	cout << (v[0][0] * (v[1][0] + v[1][1]) + v[1][0] * v[0][1]) ;
}