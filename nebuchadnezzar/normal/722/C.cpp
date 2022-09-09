#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];
ll pref[MAXN];

set<pair<ll, pii>> have;
set<pii> edges;

ll get(int l, int r) {
 	return pref[r] - pref[l];
}

int rem(int l, int r) {
 	have.erase({get(l, r), {l, r}});
 	edges.erase({l, r});
 	return 0;
}

int add(int l, int r) {
 	have.insert({get(l, r), {l, r}});
 	edges.insert({l, r});
 	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arr + i);
	 	pref[i + 1] = pref[i] + arr[i];
	}

	add(0, n);

	for (int i = 0; i < n; ++i) {
		/*
		cerr << "i: " << i << endl;
		for (auto p: have) {
		 	cerr << p.ff << " " << p.ss.ff << " " << p.ss.ss << endl;
		}*/
	 	int pos;
	 	scanf("%d", &pos);
	 	--pos;
		auto it = edges.upper_bound({pos, (int) 1e9});
		--it;
		pii p = *it;
		rem(p.ff, p.ss);
		if (p.ff < pos) {
		 	add(p.ff, pos);
		}
		if (pos + 1 < p.ss) {
		 	add(pos + 1, p.ss);
		}
		if (i < n - 1) {
    		auto it2 = have.end();
    		--it2;
    		cout << it2 -> ff << "\n";
		}
	}

	cout << 0 << "\n";
	

	#ifdef LOCAL
		cerr << "time: " << clock() << endl;
	#endif
	return 0;
}