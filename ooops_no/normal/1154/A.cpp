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
#include<deque>
using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	vector<int> a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a.begin(), a.end());
	cout << a[3] - a[0] << " " << a[3] - a[1] << " " << a[3] - a[2];
}