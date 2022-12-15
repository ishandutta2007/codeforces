#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 5e5;

ll height[MAXN];

int lft[MAXN];
int rht[MAXN];

int left_son[MAXN];
int par[MAXN];
int right_son[MAXN];
int go[MAXN];
ll best_sol[MAXN];
ll sol[MAXN];
int n;

ll calc_sol(int u, int l, int r)
{
	if (u == -1 or u == n)
		return 0;
	if (l > r) return 0;
	if (best_sol[u] != -1)
		return best_sol[u];
	go[u] = 0;
	best_sol[u] = calc_sol(left_son[u], l, u-1) + height[u] * (r - u+1);
	if (best_sol[u] < calc_sol(right_son[u], u+1, r) + height[u] * (u-l+1))
		go[u]= 1, best_sol[u] = calc_sol(right_son[u],u+1,r) + height[u] * (u-l+1);
	return best_sol[u];
}

void comp_sol(int u, int l, int r)
{
	if (u == -1 or u == n) return;
	if (l > r) return;

	if (go[u] == 0)
	{
		for (int j(u); j <= r; ++j)
			sol[j] = height[u];
		comp_sol(left_son[u], l, u-1);
	}
	else
	{
		for (int j(l); j <= u; ++j)
			sol[j] = height[u];
		comp_sol(right_son[u], u+1, r);
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> height[i];
	
	lft[0] = -1;
	for (int i(1); i < n; ++i)
	{
		int j = i-1;
		while (j >= 0 and height[j] >= height[i])
			j = lft[j];
		lft[i] = j;
	}
	rht[n-1] = n;
	for (int i(n-2); i >= 0; --i)
	{
		int j = i+1;
		while (j < n  and height[j] > height[i])
			j = rht[j];
		rht[i] = j;
	}
	int bst(0);
	for (int i(0); i< n; ++i)
		left_son[i] = right_son[i] = -1;
	for (int i(0); i < n; ++i)
	{
		if (lft[i] == -1 and rht[i] == n)
			bst = i;
		else if (lft[i] == -1)
			left_son[rht[i]] = i;
		else if (rht[i] == -1)
			right_son[lft[i]] = i;
		else
		{
			if (height[lft[i]] < height[rht[i]])
				left_son[rht[i]] = i;
			else
				right_son[lft[i]] = i;
		}
	}

	for (int i(0); i < n; ++i)
		best_sol[i] = -1;
	calc_sol(bst, 0, n-1);
	comp_sol(bst, 0, n-1);
	for (int i(0); i < n; ++i)
		cout << sol[i] << ' ';
	cout<<endl;
}