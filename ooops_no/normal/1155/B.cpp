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
	int cnt = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') {
			if (cnt >= (n - 11) / 2) {
				break;
			}
			else {
				cnt++;
			}
		}
		else {
			cnt1++;
		}
	}
	if (cnt1 <= (n - 11) / 2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}