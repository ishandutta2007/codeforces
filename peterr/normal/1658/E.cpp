#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int a[MAXN][MAXN];
int ans[MAXN][MAXN];
pair<int, int> nums[MAXN * MAXN + 1];
int n, k;

template<class Fun, int Init>
struct Filler
{
	const Fun fun;
	int val;
	
	Filler(): fun(Fun()), val(Init) {}
	
	void operator()(int newval)
	{
		//cout << "operator " << val << " " << newval << endl;
		for (int i = val + 1; i <= newval; i++)
		{
			for (int r = 0; r < n; r++)
			{
				int c = fun(r, i);
				//cout << "considering " << r << " " << c << endl;
				if (c < 0 || c >= n || ans[r][c])
					continue;
				//cout << "erasing " << r << " " << c << endl;
				ans[r][c] = 2;
				nums[a[r][c]] = {-1, -1};
			}
		}
		val = max(val, newval);
	}
};

using TR = Filler<decltype([](int r, int z){return r-z;}), -MAXN>;
using TL = Filler<decltype([](int r, int z){return z-r;}), -1>;
using BR = Filler<decltype([](int r, int z){return -r-z;}), -2 * MAXN>;
using BL = Filler<decltype([](int r, int z){return r+z;}), -MAXN>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			nums[a[i][j]] = {i, j};
		}
	}
	TR tr;
	TL tl;
	BR br;
	BL bl;
	int ptr = n * n;
	while (1)
	{
		while (ptr >= 1 && nums[ptr].first == -1)
			ptr--;
		if (!ptr)
			break;
		pair<int, int> pr = nums[ptr];
		nums[ptr] = {-1, -1};
		int r = pr.first;
		int c = pr.second;
		ans[r][c] = 1;
		//cout << "r c " << r << " " << c << endl;
		tr(r-c-k-1);
		tl(r+c-k-1);
		br(-r-c-k-1);
		bl(c-r-k-1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << (ans[i][j] == 1 ? 'M' : 'G');
		cout << "\n";
	}
	return 0;
}