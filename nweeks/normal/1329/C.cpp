#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = (1<<21) +2;

int heap[MAXN];
int depth[MAXN];
int sol_steps[MAXN];
ll sol;
int cur;
int g, h;

void calc_depth(void)
{
	depth[1] = 1;
	for (int i(2); i < MAXN; ++i)
		depth[i] = 1 + depth[i/2];
}

bool try_rem(int pos)
{
	if (depth[pos] == h) return true;

	if (depth[pos] <= g and heap[2*pos]+heap[2*pos+1] == 0)
		return false;
	if (heap[2*pos] + heap[2*pos+1] == 0)
		return true;
	if (heap[2*pos] > heap[2*pos+1])
		return try_rem(2*pos);
	return try_rem(2*pos+1);
}

void rem(int pos)
{
	if (heap[2*pos] + heap[2*pos+1] == 0)
	{
		heap[pos]= 0;
		return ;
	}
	if (heap[2*pos] > heap[2*pos+1])
	{
		heap[pos] = heap[2*pos];
		rem(2*pos);
	}
	else
	{
		heap[pos] = heap[2*pos+1];
		rem(2*pos+1);
	}
}

void comp_sol(int pos)
{
	if (heap[pos] == 0)
		return ;

	while (try_rem(pos))
	{
		sol -= heap[pos];
		sol_steps[cur++] = pos;
		rem(pos);
	}
	comp_sol(2*pos);
	comp_sol(2*pos+1);
}

void solve(void)
{
	cin >> h >> g;
	int n = (1<<h) - 1;
	sol = 0;
	cur = 0;
	for (int i(1); i <= n; ++i)
	{
		cin >> heap[i];
		sol += heap[i];
	}
	comp_sol(1);	
	

	for (int i(1); i <= n; ++i)
		heap[i] = 0;
	cout << sol << '\n';
	for (int i(0); i < ((1<<h) - (1<<g)); ++i)
		cout << sol_steps[i] << ' ';
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	calc_depth();

	int t;
	cin >> t;
	while (t--)
		solve();
}