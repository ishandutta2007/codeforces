#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;


int main()
{
	int n, start, x; cin >> n >> start >> x;

	srand(time(0));

	map<int, int> mp;
	vector<int> perm(n); FOR (i, 0, n - 1) perm[i] = i + 1;
	swap(perm[start-1], perm[0]);
	random_shuffle(perm.begin() + 1, perm.end());

	int fv;
	for (int i = 0; i < min(n, 1000); ++i) {
		int q = perm[i];
		cout << "? " << q << endl;
		int val, nxt;
		cin >> val >> nxt;
		mp[val] = q;
		if (i == 0) fv = val;
	}

	map<int,int>::iterator st = mp.end();
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->F <= x) {
			st = it;
		}
	}
	if (st == mp.end()) {
		cout << "! " << fv << endl;
		return 0;
	}
	int pos = st->S;
	int ctr = min(n, 1000);
	while (pos != -1) {
		assert(ctr + 1 <= 1999);
		++ctr;
		cout << "? " << pos << endl;
		int val, nxt;
		cin >> val >> nxt;
		assert(val != -1);
		if (val >= x) {
			cout << "! " << val << endl;
			return 0;
		}
		pos = nxt;
	}

	cout << "! -1" << endl;

	return 0;
}