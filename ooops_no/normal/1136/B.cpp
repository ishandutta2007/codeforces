/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
using namespace std;

#define int long long
#define pb push_back
#define ld long double

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int m, n;
	cin >> n >> m;
	cout << 6 + min(n - m, m - 1) + (n - 2) * 3;
}