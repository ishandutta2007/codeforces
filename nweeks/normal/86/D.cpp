#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXVAL = 1e6+1;
const int BLOCKSIZE = ceil(sqrt(MAXN));

struct Query
{
	int l, r, id;

	bool operator<(Query other) const
	{
		if (l/BLOCKSIZE < other.l/BLOCKSIZE)
			return true;
		if (l/BLOCKSIZE > other.l/BLOCKSIZE)
			return false;
		return r < other.r;
	}
} query[MAXN];

int arr[MAXN];
long long ans[MAXN];
int occ[MAXVAL];
long long curans(0);

inline void add(int x)
{
	curans -= (long long)occ[x] * occ[x] * x;
	occ[x]++;
	curans += (long long)occ[x] * occ[x] * x;
}

inline void remove(int x)
{
	curans -= (long long)occ[x] * occ[x] * x;
	occ[x]--;
	curans += (long long)occ[x] * occ[x] * x;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	for (int i(0); i < N; ++i)
		cin >> arr[i];
	for (int q(0); q < Q; ++q)
	{
		int l, r;
		cin >> l >> r;
		query[q] = {l-1, r-1, q};
	}

	sort(query, query + Q);

	int l(0), r(0);
	add(arr[0]);

	for (int i(0); i < Q; ++i)
	{
		while (l < query[i].l)
			remove(arr[l++]);
		while (l > query[i].l)
			add(arr[--l]);
		while (r < query[i].r)
			add(arr[++r]);
		while (r > query[i].r)
			remove(arr[r--]);
		ans[query[i].id] = curans;
	}
	for (int q(0); q < Q; ++q)
		cout << ans[q] << '\n';
}