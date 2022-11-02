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
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i + 1]) {
			cout << "YES" << endl << i + 1 << " " << i + 2;
			return 0;
		}
	}
	cout << "NO";
}