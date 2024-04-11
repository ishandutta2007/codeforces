// this is another solution taken from the onsite, in an attempt to improve by probability.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define wait system("pause")
#define finish(x) return cout << (x) << endl, 0
#define debug cout << "ok" << endl
using namespace std;

int n, m;
string s, ss, t;
vector<int> op;

bool check(string t1, string t2) {
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	for (int i = 0; i < n; i++) if (t1[i] != t2[i]) return false;
	return true;
}

int find(int from, char c) {
	//  cout << "finding in " << s << " from " << from << " c " << c << endl;
	while (s[from] != c)
		from++;

	//  cout << "returning " << from << endl;
	return from;
}

void work(int len) {
	//  cout << "doing " << len << endl;
	if (len <= 0 || len > n) return;
	op.push_back(len);
	string tmp = "";
	for (int i = 0; i < len; i++) {
		tmp.push_back(s.back());
		s.pop_back();
	}
	s = tmp + s;
	//  cout << "after working on " << len << " s became " << s << endl;
}

int r = 0;

bool solve(bool somebool = true) {
	r = 0;
	if (!check(s, t)) return 0;
	for (int i = 0, at; i < n; i++) {
		at = find(i, t[i]);
		if (r || at > i) {
			if (!r) {
				work(n - i);
				at = find(0, t[i]);
				work(n - at - 1);
				work(1);
			}
			else {
				work(n - at - 1);
				work(n - (i + n - at - 1));
				work(i);
			}
			r ^= 1;
		}
	}

	if (s.compare(t) != 0) {
		bool uh = true;
		for (int i = 0; uh && i < n; i++) {
			reverse(s.begin(), s.begin() + i + 1);
			if (s.compare(t) == 0) {
				reverse(s.begin(), s.begin() + i + 1);
				work(n - i - 1);
				work(n);
				uh = false;
			}
			else reverse(s.begin(), s.begin() + i + 1);
		}
	}
	if (somebool && op.size() > 5100) return 0;
	cout << op.size() << endl;
	for (const auto &i : op) cout << i << " ";
	return 1;
	//	wait;
}

void change(int len) {
	string tmp = "";
	while (len--) {
		tmp.push_back(ss.back());
		ss.pop_back();
	}
	ss = tmp + ss;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> s >> t;
	if (!check(s, t)) finish(-1);
	ss = s;
	vector<int> something;
	for (int i = 0; i < n; i++) something.push_back(i + 1);
	random_shuffle(something.begin(), something.end());

	if (solve()) return 0;
	for (int i = 0; i < 50; i++) {
		op.clear();
		change(something[i]);
		s = ss;
		for (int j = 0; j <= i; j++) op.push_back(something[j]);
		if (solve()) return 0;
	}
	op.clear();
	s = ss;
	for (int j = 0; j <= 49; j++) op.push_back(something[j]);
	if (solve(false)) return 0;
	cout << -1 << endl;
}