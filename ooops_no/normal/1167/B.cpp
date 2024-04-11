#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
using namespace std;

#define int long long
#define pb push_back

vector<int> v(4);
vector<int> used(100);
vector<int> it{ 4, 8, 15, 16, 23, 42 };
deque<int> q;

void func(int l, int i) {
	if (i == 4) {
		cout << "! ";
		for (auto to : q) {
			cout << to << " ";
		}
		for (auto to : it) {
			if (!used[to]) {
				cout << to;
			}
		}
		exit(0);
	}
	for (auto to : it) {
		if (!used[to]) {
			q.push_back(to);
			if (i == -1) {
				used[to] = 1;
				func(to, i + 1);
			}
			else {
				if (v[i] == l * to) {
					used[to] = 1;
					func(to, i + 1);
				}
			}
			used[to] = 0;
			if (!q.empty()) q.pop_back();
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << '?' << " " << 1 << " " << 2 << endl;
	cout << '?' << " " << 2 << " " << 3 << endl;
	cout << '?' << " " << 3 << " " << 4 << endl;
	cout << '?' << " " << 4 << " " << 5 << endl;
	cin >> v[0] >> v[1] >> v[2] >> v[3];
	func(0, -1);
}