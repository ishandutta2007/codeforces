#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E4;
int type[MAXN];
int ans[MAXN];
int hidden[MAXN];
int cnt = 0;

int query(int a, int b, int c)
{
	cnt++;
	a++;
	b++;
	c++;
	cout << "? " << a << " " << b << " " << c << endl;
	int q;
	cin >> q;
	//int sum = hidden[a] + hidden[b] + hidden[c];
	//return sum >= 2;
	return q;
}

void solve0(int group_ind, int where1)
{
	if (query(group_ind * 3, group_ind * 3 + 1, where1) == 0)
	{
		ans[group_ind * 3] = ans[group_ind * 3 + 1] = 0;
		ans[group_ind * 3 + 2] = query(where1, group_ind * 3, group_ind * 3 + 2);
	}
	else
	{
		ans[group_ind * 3 + 2] = 0;
		ans[group_ind * 3 + 1] = query(where1, group_ind * 3 + 2, group_ind * 3 + 1);
		ans[group_ind * 3] = !ans[group_ind * 3 + 1];
	}
}

void solve1(int group_ind, int where0)
{
	if (query(group_ind * 3, group_ind * 3 + 1, where0) == 1)
	{
		ans[group_ind * 3] = ans[group_ind * 3 + 1] = 1;
		ans[group_ind * 3 + 2] = query(where0, group_ind * 3, group_ind * 3 + 2);
	}
	else
	{
		ans[group_ind * 3 + 2] = 1;
		ans[group_ind * 3 + 1] = query(where0, group_ind * 3 + 2, group_ind * 3 + 1);
		ans[group_ind * 3] = !ans[group_ind * 3 + 1];
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		//for (int i = 1; i <= n; i++)
		//{
			//hidden[i] = rand() % 2;
		//}
		cin >> n;
		for (int i = 0; i < n / 3; i++)
		{
			type[i] = query(i * 3, i * 3 + 1, i * 3 + 2);
		}
		int ind0 = 0;
		int ind1 = 0;
		while (type[ind0] == 1)
			ind0++;
		while (type[ind1] == 0)
			ind1++;
		bool found1 = false;
		int where1 = 0;
		for (int i = 0; i < 3; i++)
		{
			if (query(ind0 * 3, ind0 * 3 + 1, ind1 * 3 + i) == 1)
			{
				found1 = true;
				where1 = ind1 * 3 + i;
				break;
			}
		}
		int where0 = -1;
		if (found1)
		{
			solve0(ind0, where1);
			where0 = ind0 * 3;
			while (ans[where0] == 1)
				where0++;
			solve1(ind1, where0);
		}
		else
		{
			where0 = ind0 * 3;
			solve1(ind1, where0);
			where1 = ind1 * 3;
			while (ans[where1] == 0)
				where1++;
			solve0(ind0, where1);
		}
		assert(where0 != -1);
		for (int i = 0; i < n / 3; i++)
		{
			if (i == ind0 || i == ind1)
				continue;
			if (type[i] == 0)
				solve0(i, where1);
			else
				solve1(i, where0);
		}
		int num_imposters = 0;
		for (int i = 0; i < n; i++)
			num_imposters += 1 - ans[i];
		cout << "! " << num_imposters << " ";
		for (int i = 0; i < n; i++)
		{
			//assert(ans[i] == hidden[i + 1]);
			if (ans[i] == 0)
				cout << i + 1 << " ";
		}
		cout << endl;
	}
	//cout << cnt << endl;
	return 0;
}