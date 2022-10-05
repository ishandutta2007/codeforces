#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct work {
	multiset<ll> D;
	ll L, Y;
	work() {
		L = Y = 0;
	}
	ll getR() {
		return L + 2LL * D.size();
	}
	// front
	ll pop() {
		ll v = *D.begin();
		D.erase(D.begin());
		L += 2;
		Y += v;
		return v;
	}
	// assuming decrease in A
	void update(ll A, ll B) {
		while (D.size() && *D.rbegin() >= 2 * A) D.erase(prev(D.end()));
		vector<ll> diff;
		int at = -1;
		ll sl = L, sy = Y;
		while (D.size() && L <= B) {
			ll v = pop();
			diff.push_back(v);
			if (at == -1 && v >= A) at = (int)diff.size() - 1;
		}

		if (at == -1 && L <= B)
			at = diff.size();
		if (at == -1) {
			if (L - B >= 2 && diff.size()) {
				L -= 2;
				Y -= diff.back();
				D.insert(diff.back());
			}
			L -= B;
			for (int i = 0; i < B; i++)
				D.insert(A);
			return;
		}
		for (int i = 0; i < at; i++) {
			sl += 2;
			sy += diff[i];
		}
		for (int i = 0; i < sl; i++) D.insert(A);
		sy += A * (B - sl);
		sl = B - sl;
		for (int i = at; i < diff.size(); i++) {
			D.insert(diff[i]);
			if (i + 1 == diff.size() && sl < 2) break;
			D.insert(2 * A - diff[i]);
			sl -= 2;
			sy -= (2 * A - diff[i]);
		}
		L = sl;
		Y = sy;
	}
	ll query() {
		return Y;
	}
};

int n;
vector<ll> t;
vector<ll> A, B;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	t.resize(n);
	for (auto &i : t) cin >> i;
	sort(t.rbegin(), t.rend());
	for (int i = 0; i < n; i++) {
		if (i == 0 || t[i - 1] != t[i]) {
			A.push_back(t[i]);
			B.push_back(1);
		}
		else B.back()++;
	}

	work W;
	int sum = 0;
	for (int i = 0; i < A.size(); i++)
		W.update(A[i], B[i]);
	cout << W.query() << '\n';
}