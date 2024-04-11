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

const int N = 101;

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		if (j % 2 == 0) {
			a++;
		}
		else {
			b++;
		}
	}
	for (int i = 0; i < m; i++) {
		int j;
		cin >> j;
		if (j % 2 == 0) {
			c++;
		}
		else {
			d++;
		}
	}
	cout << min(a, d) + min(b, c);
}