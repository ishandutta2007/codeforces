#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}


ll solve(void)
{
	int nb_supp, taille;
	cin >> nb_supp >> taille;

	ll tot = (1LL<<taille);
	set<ll> erased;
	while (nb_supp--)
	{
		string s;
		cin>>s;
		ll numb(0);
		for (auto c : s)
			numb= 2*numb  + c-'0';
		erased.insert(numb);
		tot--;
	}

	ll cur_med = (tot - 1)/2;
	while (erased.count(cur_med))
	{
		erased.erase(cur_med);
		cur_med++;
	}

	while (SZ(erased) and *erased.begin() < cur_med)
	{
		erased.erase(erased.begin());
		cur_med++;
		while (erased.count(cur_med))
		{
			erased.erase(cur_med);
			cur_med++;
		}
	}
	while (erased.count(cur_med))
		++cur_med;


	string ret = "";
	for (int i(0);i< taille;++i)
		ret += !!(cur_med & ((1LL)<<(taille-1-i))) +'0';
	cout<<ret<<endl;
	return 0;
}