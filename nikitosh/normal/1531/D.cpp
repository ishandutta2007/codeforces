#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 4e5;

struct Node {
	bool lock;
	string res;
	Node() {}
	Node(bool lock, string res): lock(lock), res(res) {}
};

pair<Node, Node> t[N];

Node merge(const Node& cur, const pair<Node, Node>& b) {
	Node f = cur;
	if (f.lock) {
		f.res = b.snd.res.empty() ? f.res : b.snd.res;
		f.lock = b.snd.lock;
	} else {
		f.res = b.fst.res.empty() ? f.res : b.fst.res;
		f.lock = b.fst.lock;	
	}
	return f;
}

pair<Node, Node> merge(const pair<Node, Node>& a, const pair<Node, Node>& b) {
	return {merge(a.fst, b), merge(a.snd, b)};
}

pair<Node, Node> parse(const string& s) {
	if (s == "lock") 
		return {Node(true, ""), Node(true, "")};
	else if (s == "unlock") 
		return {Node(false, ""), Node(false, "")};
	return {Node(0, s), Node(1, "")};
}

void print(const string& s) {
	cout << (s.empty() ? "blue" : s) << "\n";
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	int tSize = 1;
	while (tSize < n)
		tSize *=  2;
	forn (i, n) {
		string s;
		cin >> s;
		t[tSize + i] = parse(s);
	}
	for (int i = tSize - 1; i > 0; i--) 
		t[i] = merge(t[2 * i], t[2 * i + 1]);

	print(t[1].fst.res);

	int q;
	cin >> q;
	forn (qq, q) {
		int ind;
		string s;
		cin >> ind >> s;
		ind += tSize - 1;
		t[ind] = parse(s);
		while (ind > 1) {
			ind /= 2;
			t[ind] = merge(t[2 * ind], t[2 * ind + 1]);
		} 
		print(t[1].fst.res);
	}
	
	return 0;
}