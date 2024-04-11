#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

long double PI = acos(-1);

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(15);
	long double n; cin >> n;
	long double r; cin >> r;
	long double R = (r * sin(PI / n)) / (1.0l - sin(PI / n));
	cout << R;
}