#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int mod(int a)
{
	return (a > 0 ? a : -a);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; ++i)
	{
		int f1; cin >> f1;
		int t1; cin >> t1;
		int f2; cin >> f2;
		int t2; cin >> t2;
		int time = 0;
		if(f1 != f2) {
			if(t1 <= b && t1 >= a) {
				time = mod(f1 - f2);
				f1 = f2;
			}
			else {
				if(t1 > b)
				{
					time = t1 - b + mod(f1 - f2);
					t1 = b;
					f1 = f2;
				}
				else
				{
					time = a - t1 + mod(f1 - f2);
					t1 = a;
					f1 = f2;
				}
			}
		}
		time += mod(t1 - t2);
		cout << time << "\n";
	}

}