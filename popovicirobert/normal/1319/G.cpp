#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

inline int lgput(int a, int b, int md) {
	int ans = 1;
	a %= md;
	while(b > 0) {
		if(b & 1) ans = (1LL * ans * a) % md;
		b >>= 1;
		a = (1LL * a * a) % md;
	}
	return ans;
}

template <int MOD1, int MOD2>
struct Hash {
    int hsh1, hsh2;

    Hash(const Hash &_hsh) : hsh1(_hsh.hsh1), hsh2(_hsh.hsh2) {}

    explicit Hash(int _hsh1 = 0, int _hsh2 = 0) : hsh1(_hsh1), hsh2(_hsh2) {}

    bool operator <(const Hash &other) const {
	if(hsh1 == other.hsh1) return hsh2 < other.hsh2;
        return hsh1 < other.hsh1;
    }

    Hash operator +(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += other.hsh1;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += other.hsh2;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator +(const int x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += x;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += x;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator -(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += MOD1 - other.hsh1;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += MOD2 - other.hsh2;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator -(const int x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 += MOD1 - x;
        if(ans.hsh1 >= MOD1) {
            ans.hsh1 -= MOD1;
        }
        ans.hsh2 += MOD2 - x;
        if(ans.hsh2 >= MOD2) {
            ans.hsh2 -= MOD2;
        }
        return ans;
    }

    Hash operator *(const Hash &other) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 = (1LL * ans.hsh1 * other.hsh1) % MOD1;
        ans.hsh2 = (1LL * ans.hsh2 * other.hsh2) % MOD2;
        return ans;
    }

    Hash operator *(const int x) const{
        Hash ans(hsh1, hsh2);
        ans.hsh1 = (1LL * ans.hsh1 * x) % MOD1;
        ans.hsh2 = (1LL * ans.hsh2 * x) % MOD2;
        return ans;
    }

    Hash operator /(const int x) const {
    	Hash ans(hsh1, hsh2);
    	ans.hsh1 = (1LL * ans.hsh1 * lgput(x, MOD1 - 2, MOD1)) % MOD1;
    	ans.hsh2 = (1LL * ans.hsh2 * lgput(x, MOD2 - 2, MOD2)) % MOD2;
    	return ans;
    }

    bool operator ==(const Hash &other) const{
        return (hsh1 == other.hsh1 && hsh2 == other.hsh2);
    }
};

const int MOD1 = 666013;
const int MOD2 = 666019;
const int MAXN = (int) 2e5;

using ModHash = Hash<MOD1, MOD2>;
ModHash sum[MAXN + 1], pw2[MAXN + 1];
char t[MAXN + 1];

struct Node {
	int pref, suff, sz;
	ModHash hsh;

	Node(int _pref = 0, int _suff = 0, int _sz = 0, ModHash _hsh = ModHash(0, 0)) : pref(_pref), suff(_suff), sz(_sz), hsh(_hsh) {}

	bool operator ==(const Node other) const {
		return pref == other.pref && suff == other.suff && sz == other.sz && hsh == other.hsh;
	}
}aint[1 << 20];

inline ModHash sum2(int l, int r) {
	if(r < 0) return ModHash(0, 0);
	return sum[r] - (l == 0 ? ModHash(0, 0) : sum[l - 1]);
}

inline Node combine(Node a, Node b) {
	if(a.sz == 0) return b;
	if(b.sz == 0) return a;
	if(a.sz == a.pref && b.sz == b.pref) {
		return {a.sz + b.sz, a.sz + b.sz, a.sz + b.sz, a.hsh * pw2[b.sz] + b.hsh};
	}
	if(a.sz == a.pref) {
		return {a.sz + b.pref, b.suff, a.sz + b.sz, a.hsh * pw2[b.sz] + b.hsh};
	}

	assert(a.suff <= 1);
	if(a.suff) {
		a.hsh = (a.hsh - 1) / 2;
		a.suff = 0, a.sz--;
		b.suff += (b.sz == b.suff);
		b.hsh = b.hsh + pw2[b.sz];
		b.pref++, b.sz++;
	}
	
	Node ans;
	int num = b.pref / 2;
	int odd = b.pref % 2;
	ans.pref = a.pref + 2 * num;
	ans.suff = (b.sz == b.suff ? b.sz % 2 : b.suff);
	ans.sz = a.sz + b.sz;

	//1110101010|1111010101
	int sz = ans.sz;
	ans.hsh = sum2(0, a.pref - 1) * pw2[sz - a.pref] + sum2(0, 2 * num - 1) * pw2[sz - a.pref - 2 * num];
	sz -= (a.pref + 2 * num);
	ans.hsh = ans.hsh + (a.hsh - sum2(0, a.pref - 1) * pw2[a.sz - a.pref]) * pw2[sz - (a.sz - a.pref)];
	sz -= (a.sz - a.pref);
	ans.hsh = ans.hsh + b.hsh - sum2(0, b.pref - 1 - odd) * pw2[b.sz - b.pref + odd];

	return ans;
}

void build(int nod, int left, int right) {
	if(left == right) {
		int ch = t[left] - '0';
		aint[nod] = {ch, ch, 1, ModHash(ch, ch)};
	}
	else {
		int mid = (left + right) / 2;
		build(2 * nod, left, mid);
		build(2 * nod + 1, mid + 1, right);
		aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1]);
	}
}

Node query(int nod, int left, int right, int l, int r) {
	if(l <= left && right <= r) {
		//cerr << left << " " << right << " " << l << " " << r << "\n";
		return aint[nod];
	}
	else {
		int mid = (left + right) / 2;
		Node ans;
		if(l <= mid) ans = combine(ans, query(2 * nod, left, mid, l, r));
		if(mid < r)  ans = combine(ans, query(2 * nod + 1, mid + 1, right, l, r));
		return ans;
	}
}

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n, q;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> (t + 1) >> q;

	pw2[0] = sum[0] = ModHash(1, 1);
	for(i = 1; i <= n; i++) {
		pw2[i] = pw2[i - 1] * 2;
		sum[i] = sum[i - 1] + pw2[i];
	}
	build(1, 1, n);

	while(q--) {
		int l1, l2, len; cin >> l1 >> l2 >> len;
		if(query(1, 1, n, l1, l1 + len - 1) == query(1, 1, n, l2, l2 + len - 1)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}