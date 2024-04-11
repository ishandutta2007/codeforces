#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int sizeofval = 30;

struct trie {
	struct node {
		int l = -1, r = -1, par = -1;
		int count = 0, value;
		node(int pp = -1) {
			l = -1, r = -1, par = pp, count = 0;
		}
	};

	int st = 1 << (sizeofval - 1);
	int nxt = 1;
	vector<node> t = { node() };

	trie() {
		st = 1 << (sizeofval - 1);
		nxt = 1;
		t = { node() };
	}

	void insert(int x) {
		int at = 0;
		for (int i = st; i > 0; i >>= 1) {
			if (x & i) {
				if (t[at].r == -1) t[at].r = nxt++, t.push_back(node(at));
				at = t[at].r;
			}
			else {
				if (t[at].l == -1) t[at].l = nxt++, t.push_back(node(at));
				at = t[at].l;
			}
			t[at].count++;
		}
		t[at].value = x;
	}
	void erase(int ind) {
		while (ind > 0) t[ind].count--, ind = t[ind].par;
	}
	int findmin(int x) {
		int rtn = 0, at = 0;
		for (int i = st; i > 0; i >>= 1) {
			if (t[at].l == -1 || t[at].r == -1 || t[t[at].l].count == 0 || t[t[at].r].count == 0) {
				if (t[at].l != -1 && t[t[at].l].count != 0) at = t[at].l;
				else at = t[at].r, rtn += i;
			}
			else {
				if (x & i) at = t[at].r, rtn += i;
				else at = t[at].l;
			}
		}
		erase(at);
		return x ^ rtn;
	}
};

int n, a[300003], b[300003];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	trie t;
	for (int i = 0; i < n; i++) t.insert(b[i]);
	for (int i = 0; i < n; i++)
		cout << t.findmin(a[i]) << " ";
}