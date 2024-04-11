#include"bits/stdc++.h"
using namespace std;

int n;
char buf[500002];
vector<string> v;

map<int, multiset<int> > mp;

bool use[100002];

map<int, int> d;
map<int, int> u;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		v.push_back(buf);
	}
	int ans = 0;
	int zero = 0;
	for (int i = 0; i < v.size(); i++) {
		int stk = 0;
		int mint = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == '(') {
				stk++;
			}
			else {
				stk--;
				mint = min(mint, stk);
			}
		}
		if (mint == 0 && stk == 0) {
			zero++;
			continue;
		}
		if (mint == 0&&stk>0) {
			int need_stk = 0 - stk;
			if (d[need_stk]) {
				d[need_stk]--;
				ans++;
				continue;
			}
			u[stk]++;
			continue;
		}
		if (mint == stk) {
			int need_stk = 0 - stk;
			if (u[need_stk]) {
				u[need_stk]--;
				ans++;
				continue;
			}
			d[stk]++;
		}
	}
	cout << ans+zero/2 << endl;
	return 0;
}