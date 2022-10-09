#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 50;

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

int tag[N << 2], mn[N << 2];

void push_up(int o)
{
	mn[o] = min(mn[lc(o)], mn[rc(o)]);
}

void maintain(int o, int v)
{
	mn[o] += v;
	tag[o] += v;
}

void push_down(int o)
{
	if (tag[o])
	{
		maintain(lc(o), tag[o]);
		maintain(rc(o), tag[o]);
		tag[o] = 0;
	}
}

void add(int o, int l, int r, int ql, int qr, int v)
{
	if (ql <= l && r <= qr)
	{
		maintain(o, v);
	}
	else
	{
		const int mid = l + r >> 1;
		push_down(o);
		if (ql <= mid) add(lc(o), l, mid, ql, qr, v);
		if (qr > mid) add(rc(o), mid + 1, r, ql, qr, v);
		push_up(o);
	}
}

int main()
{
	int n, m;
	ios::sync_with_stdio(false);
	memset(mn, 0, sizeof mn);
	cin >> n >> m;
	vector<tuple<int, int, int>> segs;
	vector<int> buc;
	buc.push_back(1); buc.push_back(m);
	for (int i = 1; i <= n; ++i)
	{
		int l, r, w;
		cin >> l >> r >> w;
		segs.emplace_back(w, l, r);
		buc.push_back(l);
		buc.push_back(r);
	}
	sort(segs.begin(), segs.end());
	sort(buc.begin(), buc.end());
	buc.erase(unique(buc.begin(), buc.end()), buc.end());
	for (auto &[w, l, r] : segs)
	{
		l = lower_bound(buc.begin(), buc.end(), l) - buc.begin() + 1;
		r = lower_bound(buc.begin(), buc.end(), r) - buc.begin() + 1;
	}
	int len = buc.size();
	int ans = 1e9;
	int j = 0, cur_w = get<0>(segs[0]);
	for (int i = 0; i < segs.size(); ++i)
	{
		auto [w, l, r] = segs[i];
		add(1, 1, len - 1, l, r - 1, 1);
		if (mn[1] > 0) ans = min(ans, w - cur_w);
		while (mn[1] > 0 && j < i)
		{
			ans = min(ans, w - cur_w);
			add(1, 1, len - 1, get<1>(segs[j]), get<2>(segs[j]) - 1, -1);
			cur_w = get<0>(segs[j + 1]);
			++j;
		}
	}
	cout << ans << '\n';
}