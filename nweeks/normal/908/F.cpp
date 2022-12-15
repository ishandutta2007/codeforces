#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	string col;
	col.resize(n);
	vector<ll> pos(n);
	for (int i(0); i < n; ++i)
		cin >> pos[i] >> col[i];

	ll cst(0);
		
	bool g(false);
	for (auto c : col)
		g = g || (c=='G');
	if (!g)
	{
		int fst_r(n), lst_r(0);
		for (int i(0); i < n; ++i)
			if (col[i] == 'R')
			{
				fst_r = min(fst_r, i);
				lst_r = max(lst_r, i);
			}
		int fst_b(n), lst_b(0);
		for (int i(0); i < n; ++i)
			if (col[i] == 'B')
			{
				fst_b = min(fst_b, i);
				lst_b = max(lst_b, i);
			}
		if (fst_r != n)
			cst += pos[lst_r] - pos[fst_r];
		if (fst_b != n)
			cst += pos[lst_b] - pos[fst_b];
		cout << cst << endl;
		return 0;
	}

	array<int, 2> seen({0,0});
	int l(0);
	while (col[l] != 'G')
	{
		if (col[l] == 'R' and !seen[0]) seen[0] = pos[l];
		else if(col[l]=='B' and !seen[1]) seen[1] = pos[l];
		++l;
	}
	if (seen[0])
		cst += pos[l] - seen[0];
	if (seen[1])
		cst += pos[l] - seen[1];

	while (l+1 < n)
	{
		int r = l+1;
		array<ll,2> heaviest({0,0});
		array<int,2> lst({l,l});
		while (r < n and col[r] != 'G')
		{
			if (col[r] == 'B')
			{
				heaviest[0] = max(heaviest[0], pos[r]-pos[lst[0]]);
				lst[0]=r;
			}
			else
			{
				heaviest[1] = max(heaviest[1], pos[r]-pos[lst[1]]);
				lst[1]=r;
			}
			++r;
		}
		if (r == l+1)
			cst += pos[r] - pos[l];
		else if (r < n)
		{
			heaviest[0] = max(heaviest[0], pos[r]-pos[lst[0]]);
			heaviest[1] = max(heaviest[1], pos[r]-pos[lst[1]]);
			cst += min(2*(pos[r]-pos[l]), 
							3*(pos[r]-pos[l]) - heaviest[0]-heaviest[1]);
		}
		else
			cst += pos[lst[0]] +pos[lst[1]] - 2*pos[l];
		l = r;
	}
	cout << cst << endl;
}