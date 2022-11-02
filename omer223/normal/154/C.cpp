
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll modpow(ll a, ll b, ll md) { ll res = 1; a %= md; for (; b; b >>= 1) { if (b & 1)res = res * a%md; a = a * a%md; }return res; }


struct SingHash {
private:
public:
	ll p, m;
	vector<ll> pows, invpows;
	SingHash(ll prime, ll mod, int MAX_SIZE) {
		p = prime;
		m = mod;
		pows.resize(MAX_SIZE);
		invpows.resize(MAX_SIZE);
		for (int i = 0; i < MAX_SIZE; i++) {
			if (!i)pows[i] = 1;
			else pows[i] = (pows[i - 1] * p) % m;
		}
		invpows[MAX_SIZE - 1] = modpow(pows[MAX_SIZE - 1], m - 2, m);
		for (int i = MAX_SIZE - 2; i >= 0; i--)invpows[i] = (invpows[i + 1] * p) % m;
	}
	ll compHash(vector<int> v) { //INT OR STRING??
		ll res = 0;
		for (int i = 0; i < v.size(); i++) {
			res += (pows[i] * (v[i] + 1)); res %= m; //CHANGE ACCORDINGLY
		}
		return res;
	}
	vector<ll> compArr(vector<int> v) {
		if (!v.size()) return vector<ll>{};
		vector<ll> res(v.size(), 0);
		ll tmp;
		for (int i = 0; i < v.size(); i++) {
			tmp = (pows[i] * (v[i] + 1)) % m; //CHANGE
			if (!i)res[i] = tmp;
			else res[i] = (res[i - 1] + tmp) % m;
		}
		return res;
	}
	ll subarrHash(vector<ll> table, int i, int j) {
		if (i > j)return -1;
		if (!i)return table[j];
		return ((table[j] - table[i - 1]) *invpows[i]) % m;
	}
};

struct DoubHash {
private:
public:
	SingHash* myHash[2];
	DoubHash(ll alphabets[2], ll mods[2], int MAX_SIZE) {
		myHash[0] = new SingHash(alphabets[0], mods[0], MAX_SIZE);
		myHash[1] = new SingHash(alphabets[1], mods[1], MAX_SIZE);
	}
	pll computeHash(vector<int> v) { //CHECK ACCORDINGLY
		return mp(myHash[0]->compHash(v), myHash[1]->compHash(v));
	}
	pair<vll, vll> computeHashArray(vector<int> v) {
		return mp(myHash[0]->compArr(v), myHash[1]->compArr(v));
	}
	pll subHash(pair<vll, vll> table, int i, int j) {
		return mp(myHash[0]->subarrHash(table.first, i, j), myHash[1]->subarrHash(table.second, i, j));
	}
};

struct DisjointSet {
	int fcnt;
	vi f, sz, acsz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		acsz.resize(size);
		fcnt = size;
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = 1;
			acsz[i] = 1;
		}
	}
	int father(int src) {
		if (src == f[src])return src;
		return f[src] = father(f[src]);
	}
	bool unite(int a, int b) {
		int fa = father(a), fb = father(b);
		if (sz[fa] < sz[fb])swap(fa, fb);
		if (fa == fb)return false;
		f[fb] = fa;
		fcnt--;
		sz[fa] = max(sz[fa], sz[fb] + 1);
		acsz[fa] += acsz[fb];
		return true;
	}
};

void subtract(ll &a, ll b, ll md) {
	if (a >= b)a = (a - b) % md;
	else a = (a - b) % md + md;
}
const int sz = 1e6 + 5;
bitset<sz> isftr;
vector<int> v[sz];
pll val[sz];
int n, m;
pair<vll, vll> tables[sz];

int main() {
	fast;
	DoubHash d(new ll[2]{ 1000003 , 1000033 }, new ll[2]{ 1000000007,1000000009 }, 1000000);
	cin >> n >> m;
	DisjointSet dsu(n);
	int a, b;
	foru(i, 0, m) {
		cin >> a >> b; a--; b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	foru(i, 0, n)sort(v[i].begin(), v[i].end());//check collisions by size??
	foru(i, 0, n) {
		val[i] = (v[i].size() ? d.computeHash(v[i]) : mp(-1LL, -1LL));
		tables[i] = d.computeHashArray(v[i]);
	}
	ll p1inv = d.myHash[0]->invpows[1], p2inv = d.myHash[1]->invpows[1],
		m1 = d.myHash[0]->m, m2 = d.myHash[1]->m;
	foru(i, 0, n) {
		for (int k : v[i]) {
			int size = v[k].size();
			if (v[k].size() != v[i].size())continue;
			if (size <= 1) {
				dsu.unite(i, k);
				continue;
			}
			int l = 1, r = size, mid, indexInFirst,indexInSecond;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				if (v[i][mid - 1] > k)r = mid - 1;
				else if (v[i][mid - 1] < k)l = mid + 1;
				else {
					indexInFirst = mid - 1;
					break;
				}
			}
			l = 1, r = size;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				if (v[k][mid - 1] > i)r = mid - 1;
				else if (v[k][mid - 1] < i)l = mid + 1;
				else {
					indexInSecond = mid - 1;
					break;
				}
			}
			ll hif, his, hkf, hks;
			hif = (indexInFirst ? tables[i].first[indexInFirst - 1] : 0);
			hkf = (indexInSecond ? tables[k].first[indexInSecond - 1] : 0);
			his = (indexInFirst ? tables[i].second[indexInFirst - 1] : 0);
			hks = (indexInSecond ? tables[k].second[indexInSecond - 1] : 0);
			hif += ((tables[i].first[size - 1] - tables[i].first[indexInFirst] + m1)*p1inv) % m1;
			his += ((tables[i].second[size - 1] - tables[i].second[indexInFirst] + m2)*p2inv) % m2;
			hkf += ((tables[k].first[size - 1] - tables[k].first[indexInSecond] + m1)*p1inv) % m1;
			hks += ((tables[k].second[size - 1] - tables[k].second[indexInSecond] + m2)*p2inv) % m2;
			if (hif % m1== hkf %m1&& his%m2 == hks%m2)dsu.unite(i, k);
		}
	}
	unordered_map<ll, int> mem;
	foru(i, 0, n) {
		ll pp = val[i].first * m2 + val[i].second;
		if (mem.find(pp) == mem.end())mem[pp] = i;
		else dsu.unite(i, mem[pp]);
	}
	foru(i, 0, n) {
		if (dsu.f[i] == i)isftr[i] = 1;
	}
	ll tot = 0;
	foru(i, 0, n) {
		if (!isftr[i]) continue;
		ll famt = (dsu.acsz[i]);
		tot += ((famt*(famt - 1)) / 2);
	}
	cout << tot <<endl;
	return 0;
}