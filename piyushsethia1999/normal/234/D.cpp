#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int max(std::vector<int>& v, int I)
{
	int p = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i] > p && i != I)
			p = v[i];
	}
	return p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
		
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m, k;
	cin >> m >> k;
	std::vector<bool> isFav(m+1, false);
	int x;
	for (int i = 0; i < k; ++i)
	{
		cin >> x;
		isFav[x] = true;
	}
	int n;
	cin >> n;
	string filmname;
	std::vector<int> nactors(n);
	std::vector<int> mi(n);
	std::vector<int> ma(n);
	int known;
	int fav;
	for (int i = 0; i < n; ++i)
	{
		known = 0;
		fav = 0;
		cin >> filmname;
		cin >> nactors[i];
		for (int j = 0; j < nactors[i]; ++j)
		{
			cin >> x;
			if(x != 0)
			{
				known++;
				if(isFav[x])
					fav++;
			}
		}
		int notinlistnotfav = m - k - (known - fav);
		mi[i] = fav + ((nactors[i] - known - notinlistnotfav) > 0 ? (nactors[i] - known - notinlistnotfav): 0);
		ma[i] = min(fav + nactors[i] - known, k);
	}
	print(mi, ma);
	if(n == 1)
	{
		cout << 0;
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			x = max(ma, i);
			if(mi[i] >= x)
				cout << 0;
			else {
				x = max(mi, i);
				if(ma[i] < x)
				{
					cout << 1;
				}
				else{
					cout << 2;
				}
			}
			cout << "\n";
		}
	}
}