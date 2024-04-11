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
	#endif
	ll n, k, s;
	cin >> n>> k>> s;
	if((n-1)*k < s || s < k)
	{
		cout << "NO";
		exit(0);
	}
	cout << "YES\n";
	ll d = s / k;
	ll r = s % k;
	ll ip = 1;
	bool inc = true;
	for (int i = 0; i < r; ++i)
	{
		if(inc) {
			ip += d + 1;
			inc = false;
		}
		else {
			ip -= (d + 1);
			inc = true;
		}
		cout << ip << " ";
	}
	for (int i = 0; i < k - r; ++i)
	{
		if(inc) {
			ip += d;
			inc = false;
		}
		else {
			ip -= (d);
			inc = true;
		}
		cout << ip << " ";
	}
}