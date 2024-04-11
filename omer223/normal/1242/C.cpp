#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int nsz = 15, sz = 5e3 + 5;
int k, n[nsz], curnum = 1, cycid = 0;
ll a[nsz][sz];
map<ll, pii> mem; //unordered
int vis[nsz][sz];
int indeg[nsz][sz];
pii nxt[nsz][sz];
ll totsum = 0, totamt = 0, mysum[nsz];
unordered_map<int, int> cycs;
vector<vector<pii>> cycinfo;
pii dp[(1 << nsz)];
int curones[nsz + 5];
int oneeye[nsz + 5];
vector<pair<int, pii>> fininfo;

void input() {
	cin >> k;
	foru(i, 0, k) {
		cin >> n[i];
		foru(j, 0, n[i]) {
			cin >> a[i][j];
			totsum += a[i][j];
			mysum[i] += a[i][j];
			mem[a[i][j]] = { i,j };
		}
	}
	oneeye[0] = 1;
	foru(i, 1, k + 5) {
		oneeye[i] = (oneeye[i - 1] << 1);
	}
}

void findCycle(int i, int j) {
	stack<pii> stk;
	curnum++;
	vis[i][j] = curnum;
	stk.push({ i,j });
	while (true) {
		pii iter = nxt[i][j];
		if (iter.ff == -1)return;
		i = iter.ff;
		j = iter.ss;
		if (vis[i][j]) {
			if (vis[i][j] == curnum) {
				int mycyc = 0;
				vector<pii> vcyc;
				while (!stk.empty()) {
					pii tmp = stk.top(); stk.pop();
					int ti = tmp.ff, tj = tmp.ss;
					vcyc.pb({ ti,tj });
					if ((mycyc >> ti) & 1)
						return;
					mycyc |= (1 << ti); //check
					if (ti == i && tj == j) {
						cycs.insert({ mycyc,cycid++ });
						cycinfo.pb(vcyc);
						return;
					}
				}
			}
			return;
		}
		else {
			vis[i][j] = curnum;
			stk.push({ i,j });
		}
	}
}

bool fsolve(const int& ones, int i, int cnt, int curmsk, const int& outmsk) { //dont move param
	if (i == ones || 2 * (cnt + 1) > ones) {
		if (dp[curmsk].ss == -1)
			return false;
		int cont = outmsk ^ curmsk;
		if (dp[cont].ss == -1)
			return false;
		dp[outmsk] = { curmsk,cont };
		return true;
	}
	else {
		bool ret = 0;
		if (fsolve(ones, i + 1, cnt, curmsk, outmsk))
			return true;
		if (fsolve(ones, i + 1, cnt + 1, curmsk | oneeye[curones[i]], outmsk))
			return true;
		return false;
	}
}

void solve(int i,int ones, int curmsk) {
	if (i == k) {
		if (!ones || dp[curmsk].ss != -1)return;
		fsolve(ones, 0, 0, 0, curmsk);
	}
	else {
		solve(i + 1, ones, curmsk);
		curones[ones] = i;
		solve(i + 1, ones + 1, curmsk | oneeye[i]);
	}
}

void extract(int msk) {
	if (dp[msk].ff == -1) {
		vector<pii> myinfo = cycinfo[dp[msk].ss];
		int len = myinfo.size();
		for (int i = 0; i < len; i++) {
			fininfo.pb({ myinfo[i].ff,{a[myinfo[i].ff][myinfo[i].ss],myinfo[(i + 1) % len].ff } });
		}
	}
	else {
		extract(dp[msk].ff);
		extract(dp[msk].ss);
	}
}

void solvedp() {
	foru(i, 0, (1 << k))dp[i] = { -1,-1 };
	for (auto ii : cycs) {
		dp[ii.ff] = { -1,ii.ss };
	}
	solve(0, 0, 0);
	if (dp[(1 << k) - 1].ss != -1) {
		cout << "YES\n";
		extract((1 << k) - 1);
		sort(fininfo.begin(), fininfo.end());
		for (auto x : fininfo)
			cout << x.ss.ff << ' ' << x.ss.ss + 1 << '\n';
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	fast;
	input();
	if (totsum%k != 0) {
		cout << "No\n";
		return 0;
	}
	ll needsum = totsum / k;
	foru(i, 0, k) {
		foru(j, 0, n[i]) {
			ll tamt = needsum - (mysum[i] - a[i][j]);
			if (mem.find(tamt) == mem.end())nxt[i][j] = { -1, -1 };
			else {
				nxt[i][j] = mem[tamt];
				indeg[nxt[i][j].ff][nxt[i][j].ss]++;
			}
		}
	}
	queue<pii> zindeg;
	foru(i, 0, k) {
		foru(j, 0, n[i]) {
			if (!indeg[i][j])zindeg.push({ i,j });
		}
	}
	while (!zindeg.empty()) {
		pii ii = zindeg.front(); zindeg.pop();
		int i = ii.ff, j = ii.ss;
		findCycle(i, j);
	}
	foru(i, 0, k) {
		foru(j, 0, n[i]) {
			if (!vis[i][j])
				findCycle(i, j);
		}
	}
	solvedp();
	return 0;
}