#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	
	double p;
	int n;
	cin>>n;
	std::vector<std::vector<double> > P(n, std::vector<double>(n, 0.0));
	std::vector<std::vector<double> > Pdash(n, std::vector<double>(n, 0.0));
	std::vector<double> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		P[i][i] = v[i];
		Pdash[i][i] = 1-P[i][i];
	}
	for (int diff = 1; diff < n; ++diff)
	{
		for (int i = 0; i < (n - diff); ++i)
		{
			int j = i + diff;
			Pdash[i][j] = Pdash[i][j-1]*Pdash[j][j];
		}
	}
	for (int diff = 1; diff < n; ++diff)
	{
		for (int i = 0; i < (n - diff); ++i)
		{
			int j = i + diff;
			P[i][j] = P[i][j-1]*((double)(1.0) - P[j][j]) + Pdash[i][j-1]*P[j][j];
		}
	}
	double max = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if(max < P[i][j])
				max = P[i][j];
		}
	}
	cout<<max;
}