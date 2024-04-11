#include <iostream>
#include <vector>
#define flush fflush(stdout), cout.flush()
using namespace std;

struct range {
	int l, r;
	range(int l = 0, int r = 0) : l(l), r(r) {};
};

int n, x, y;
vector<range> r;

int ask(vector<int> &q) {
	cout << "? " << q.size() << " ";
	for (auto i : q) cout << i << " "; cout << endl;
	flush;
	int ans;
	cin >> ans;
	return ans;
}

void divide() {
	vector<range> temp;
	int mid;
	for (auto &i : r) {
		if (i.l == i.r)
			temp.push_back(range(i.l, i.r)), temp.push_back(range(i.l, i.r));
		else {
			mid = (i.l + i.r) / 2;
			temp.push_back(range(i.l, mid)), temp.push_back(range(mid + 1, i.r));
		}
	}
	r = temp;
}

int BS1(vector<range> &ranges, int l, int r) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	vector<int> q;
	for (int i = l; i <= mid; i++) for (int j = ranges[i].l; j <= ranges[i].r; j++) q.push_back(j + 1);
	int ans = ask(q);
	if (ans != x && ans != 0) return BS1(ranges, l, mid);
	return BS1(ranges, mid + 1, r);
}

int BS2(range ra) {
	if (ra.l == ra.r) return ra.l;
	int mid = (ra.l + ra.r) / 2;
	vector<int> q;
	for (int i = ra.l; i <= mid; i++) q.push_back(i + 1);
	int ans = ask(q);
	if (ans != x && ans != 0) return BS2(range(ra.l, mid));
	return BS2(range(mid + 1, ra.r));
}

int main() {
	cin >> n >> x >> y;
	r.push_back({ 0, n - 1 });
	bool found = false;
	while (!found) {
		divide();
		vector<int> q;
		for (int i = 0; i < r.size(); i += 2) for (int j = r[i].l; j <= r[i].r; j++) q.push_back(j + 1);
		int ans = ask(q);
		if (ans != x && ans != 0) found = true;
	}
	vector<range> temp;
	for (int i = 0; i < r.size(); i += 2) temp.push_back(range(r[i].l, r[i].r));
	int group = BS1(temp, 0, temp.size() - 1) * 2, ans1 = BS2(r[group]), ans2 = BS2(r[group + 1]);
	if (ans1 > ans2) ans1 += ans2, ans2 = ans1 - ans2, ans1 -= ans2;
	cout << "! " << ans1 + 1 << " " << ans2 + 1 << endl;
	flush;
	return 0;
}