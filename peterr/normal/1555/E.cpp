#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int MAXM = 1 << 20;
int seg[2 * MAXM];
int lz[2 * MAXM];
tuple<int, int, int> a[MAXN];

void prop(int ind)
{
	if (ind < MAXM)
	{
		lz[ind * 2] += lz[ind];
		lz[ind * 2 + 1] += lz[ind];
		seg[ind * 2] += lz[ind];
		seg[ind * 2 + 1] += lz[ind];
	}
	lz[ind] = 0;
}

int query(int l, int r, int ind=1, int lb=0, int ub=MAXM)
{
	prop(ind);
	if (lb >= r || ub <= l)
		return MAXN;
	if (lb >= l && ub <= r)
	{
		//cout << "returning from ind " << ind << " " << seg[ind] << endl;
		return seg[ind];
	}
	int mid = (lb + ub) / 2;
	return min(query(l, r, 2 * ind, lb, mid), query(l, r, 2 * ind + 1, mid, ub));
}

void inc_(int l, int r, int x, int ind=1, int lb=0, int ub=MAXM)
{
	prop(ind);
	if (lb >= r || ub <= l)
		return;
	if (lb >= l && ub <= r)
	{
		lz[ind] += x;
		seg[ind] += x;
	}
	else
	{
		int mid = (lb + ub) / 2;
		inc_(l, r, x, ind * 2, lb, mid);
		inc_(l, r, x, ind * 2 + 1, mid, ub);
		seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
	}
}

bool check(int n, int m, int val)
{
	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		while (ptr < i && get<0>(a[ptr]) < get<0>(a[i]) - val)
		{
			inc_(get<1>(a[ptr]), get<2>(a[ptr]), -1);
			ptr++;
		}
		inc_(get<1>(a[i]), get<2>(a[i]), 1);
		//cout << "incremented " << query(0, 10) << endl;
		if (query(1, m))
		{
			//cout << "weight " << val << " is valid on " << i << endl;
			while (ptr <= i)
			{
				inc_(get<1>(a[ptr]), get<2>(a[ptr]), -1);
				ptr++;
			}
			return true;
		}
	}
	while (ptr < n)
	{
		inc_(get<1>(a[ptr]), get<2>(a[ptr]), -1);
		ptr++;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int l, r, w;
		cin >> l >> r >> w;
		a[i] = {w, l, r};
	}
	sort(a, a + n);
	int ans = MAXM;
	int ptr = -1;
	for (int i = 0; i < n; i++)
	{
		while (!query(1, m))
		{
			ptr++;
			if (ptr < n)
			{
				inc_(get<1>(a[ptr]), get<2>(a[ptr]), 1);
			}
			else
				break;
		}
		if (ptr < n)
			ans = min(ans, get<0>(a[ptr]) - get<0>(a[i]));
		inc_(get<1>(a[i]), get<2>(a[i]), -1);
	}
	cout << ans << "\n";
	return 0;
}