#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
string s;
int cnt[256] = {};
vector<int> a;
vector<int> pos, pos2;

int C;
int mn;
int ans, l, r;

void add(int s, int e) {
	map<int, int> M;
	for (int i = 0; i < n; i++) {
		int v = a[i];
		if (s <= i && i <= e) v += 2;
		M[v]++;
	}
	int A = M.begin()->second;
	if (A > ans) {
		ans = A;
		l = s;
		r = e + 1;
	}
}

void work1(int s, int e) {
	int cnt = 0;
	for (int i = s; i <= e; i++)
		if (a[i] == mn + 1) cnt++;
	if (cnt > ans) {
		ans = cnt;
		l = s;
		r = e + 1;
	}
}

void work2(int s, int e) {
	int cnt = 0, mx = 0;
	int lst;
	int x = -1, y = -1;
	for (int i = s; i <= e; i++) {
		if (a[i] == mn + 1) cnt = 0, lst = i;
		else {
			if (a[i] == mn + 2) {
				cnt++;
				if (cnt > mx) {
					mx = cnt;
					x = lst + 1;
					y = i + 1;
				}
			}
		}
	}
	if (C + mx > ans) {
		ans = C + mx;
		l = x;
		r = y;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	for (const auto &i : s)
		cnt[i]++;
	if (cnt[')'] != cnt['(']) {
		cout << "0\n1 1\n";
		return 0;
	}
	if (n == 2) {
		cout << "1\n1 1\n";
		return 0;
	}

	s.insert(s.begin(), '0');
	n++;
	a.resize(n, 0);
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
	a.pop_back();
	n--;

	mn = *min_element(a.begin(), a.end());
	int c = 0;
	l = r = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == mn) c++, pos.push_back(i);
		if (a[i] == mn + 1) pos2.push_back(i);
	}
	ans = c;
	C = c;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '(') {
			if (l == -1) l = i;
			else r = i;
		}
	}

	if (mn < 0) {
		add(pos[0], pos.back());
	}
	if (mn < -1) {
		add(pos2[0], pos2.back());
	}

	for (int i = 1; i < pos.size(); i++) {
		work1(pos[i - 1] + 1, pos[i] - 1);
		work2(pos[i - 1] + 1, pos[i] - 1);
	}
	if (0 <= pos[0] - 1) {
		work1(0, pos[0] - 1);
		work2(0, pos[0] - 1);
	}
	if (pos.back() + 1 <= n - 1) {
		work1(pos.back() + 1, n - 1);
		work2(pos.back() + 1, n - 1);
	}

	cout << ans << '\n' << l << " " << r << '\n';
}