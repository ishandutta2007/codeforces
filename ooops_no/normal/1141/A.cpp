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


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	if (b % a == 0) {
		int need = b / a;
		int cnt = 0;
		while (need % 3 == 0) {
			cnt++;
			need /= 3;
		}
		while (need % 2 == 0) {
			cnt++;
			need /= 2;
		}
		if (need == 1) {
			cout << cnt;
		}
		else {
			cout << -1;
		}
	}
	else {
		cout << -1;
	}
}