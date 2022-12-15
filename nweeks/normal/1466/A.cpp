#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int nbArbres;
		cin >> nbArbres;
		set<int> aires;
		vector<int> arbres(nbArbres);
		for (auto &v : arbres)
			cin >> v;
		for (int i(0); i < nbArbres; ++i)
			for (int j(i+1); j < nbArbres; ++j)
				aires.insert((arbres[j] - arbres[i]));
		cout << SZ(aires) << endl;
	}
}