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

ll gcd(ll a, ll b) {
 	return b == 0 ? a : gcd(b, a % b);
}

int n, m;
vector<int> inp[MAXN];
vector<pii> have[MAXN];

ll check_solution(const vector<int>& v) {
 	ll lcm = 1;
	ll sol = 0;
	for (int i = 1; i <= 40; ++i) {
	 	if (v[i] == -1) {
	 	 	continue;
	 	}
	 	//assert(v[i] < i);
	 	ll tmp = gcd(lcm, (ll) i);
	 	bool flag = false;
	 	for (int j = 0; j < i / tmp; ++j) {
	 	 	if ((j * lcm + sol) % i == v[i]) {
	 	 	 	sol = j * lcm + sol;
	 	 	 	flag = true;
	 	 	 	break;
	 	 	}
	 	}
	 	if (!flag) {
	 	 	return -1;
	 	}
	 	lcm = lcm * i / tmp;
	}
	return sol;
}

int solve(const vector<pii>& v) {
	if (szof(v) == 0) {
		return 0;
	}
	int c = 0;
	int ret = 1;
	
	vector<int> now(50, -1);
	vector<int> tot(50);
	for (int i = 0; i < szof(v); ++i) {
	 	while (c < szof(v)) {
	 	 	if (now[v[c].ss] == v[c].ff) {
	 	 		++tot[v[c].ss];
	 	 	 	++c;
	 	 	 	continue;
	 	 	}
	 	 	if (now[v[c].ss] != -1) {
	 	 	 	break;
	 	 	}
	 	 	
	 	 	now[v[c].ss] = v[c].ff;
	 	 	ll tmp = check_solution(now);
	 	 	if (tmp == -1) {
	 	 	 	now[v[c].ss] = -1;
	 	 	 	break;
	 	 	}
	 	 	++tot[v[c].ss];
	 	 	++c;
	 	}
	 	ret = max(ret, c - i);
	 	--tot[v[i].ss];
	 	if (tot[v[i].ss] == 0) {
	 	 	now[v[i].ss] = -1;
	 	}
	}

	return ret;
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
	 	int k;
	 	scanf("%d", &k);
	 	for (int j = 0; j < k; ++j) {
	 	 	int num;
	 	 	scanf("%d", &num);
	 	 	--num;
	 	 	inp[i].puba(num);
	 	 	have[num].puba({i, j});
	 	}
	}

	for (int i = 0; i < m; ++i) {
		int ans = 0;
	 	vector<pii> now;

	 	for (int j = 0; j < szof(have[i]); ++j) {
	 	 	if (j > 0 && have[i][j - 1].ff + 1 < have[i][j].ff) {
	 	 	 	ans = max(ans, solve(now));
	 	 	 	now.clear();
	 	 	}
	 	 	now.puba({have[i][j].ss, szof(inp[have[i][j].ff])});
	 	}
	 	ans = max(ans, solve(now));

	 	cout << ans << "\n";
	}


	#ifdef LOCAL
		cerr << "time: " << clock() << endl;
	#endif
	return 0;
}