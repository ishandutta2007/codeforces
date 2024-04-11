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
	vector<int> v;
	while (n > 0) {
		v.pb(n & 1);
		n = n >> 1;
	}
	if (count(v.begin(), v.end(), 0) == 0) {
		cout << 0;
		return 0;
	}
	cout << count(v.begin(), v.end(), 0) * 2 + 1 << endl << 0 << " ";
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			cout << i << " ";
		}
	}

}