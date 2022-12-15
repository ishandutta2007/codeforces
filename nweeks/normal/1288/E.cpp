#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 2e6;

vector<int> seg[MAXN];
int val[MAXN];
int nxt[MAXN];
int lst[MAXN];
int n, m, p, deb;
int cnt_val;

vector<int> merge_vec(const vector<int> &v1, const vector<int> &v2)
{
	vector<int> mm;
	mm.reserve(SZ(v1) + SZ(v2));

	int j(0);
	for (int i(0); i <= SZ(v1); ++i)
	{
		while (j < SZ(v2) and (i == SZ(v1) or v2[j] <= v1[i]))
			mm.push_back(v2[j++]);
		if (i < SZ(v1))
			mm.push_back(v1[i]);
	}
	return mm;
}

void build_seg(void)
{
	while ((1<<p) < m)
		++p;

	deb = (1<<p)-1;
	for (int i(0); i < m; ++i)
		seg[deb + i] = {nxt[i]};

	for (int i(deb-1); i >= 0; --i)
		seg[i] = merge_vec(seg[2*i+1], seg[2*i+2]);
}

int cnt_less(const vector<int> &v, int x)
{
	int l(0), r(SZ(v) - 1);
	while (l < r)
	{
		int mid = (l+r+1)/2;
		if (v[mid] > x)
			r = mid-1;
		else
			l = mid;
	}
	if (v[l] <= x)
		++l;
	return l;
}

int query_less(int l, int r, int x)
{
	l += deb, r += deb;
	int ans(0);

	while (l < r)
	{
		if (l % 2 == 0)
			ans += cnt_less(seg[l], x);
		if (r % 2)
			ans += cnt_less(seg[r], x);
		l /= 2;
		r = (r-2)/2;
	}
	if (l == r)
		ans += cnt_less(seg[l], x);
	return ans;
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i(0); i < m; ++i)
	{
		cin >> val[i];
		val[i]--;
	}
	cnt_val=n;
	for (int i(0); i < cnt_val; ++i)
		lst[i] = m;
	for (int i(m-1); i >= 0; --i)
	{
		nxt[i] = lst[val[i]];
		lst[val[i]] = i;
	}

	build_seg();
	vector<int> mini(n);
	vector<int> maxi(n);
	for (int i(0); i < n; ++i)
		mini[i] = maxi[i] = i+1;

	FenwickTree fen(n);
	
	vector<bool> seen(n);
	for (int i(0); i < m; ++i)
		if (!seen[val[i]])
		{
			mini[val[i]] = 1;
			maxi[val[i]] = 1+val[i] + fen.sum(val[i], n-1);
			seen[val[i]] = true;
			fen.add(val[i], 1);
		}

	vector<int> last_seen(n, -1);
	for (int i(0); i < m; ++i)
	{
		if (last_seen[val[i]] != -1)
		{
			maxi[val[i]] = max(maxi[val[i]], 1+i-(last_seen[val[i]]+1) - query_less(last_seen[val[i]]+1, i-1, i-1));
		}
		last_seen[val[i]] = i;
	}
	for (int i(0); i < n; ++i)
		if (last_seen[i] != -1)
		{
			maxi[i] = max(maxi[i], m - last_seen[i] - query_less(last_seen[i]+1, m-1, m-1));
		}
	for (int i(0); i < n; ++i)
		if (last_seen[i] == -1)
			maxi[i] = max(maxi[i], i + 1 + fen.sum(i,n-1));

	for (int i(0); i < n; ++i)
		cout << mini[i] <<' ' << maxi[i] << '\n';
/*	while (q--)
	{
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << r - l + 1 - query_less(l, r, r) << '\n';
	}*/
}