#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m;
	std::vector<int> attk;
	std::vector<int> def;
	std::vector<int> fox(m);
	int x;
	string y;
	for (int i = 0; i < n; ++i)
	{
		cin >> y >> x;
		if(y[0] == 'A') {
			attk.pb(x);
		}
		else {
			def.pb(x);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		fox[i] = x;
	}
	sort(fox.rbegin(), fox.rend());
	sort(def.begin(), def.end());
	sort(attk.begin(), attk.end());



	int M = min(m, (int)(attk.size()));

	bool b = true;

	int maxdamage = 0;

	for (int i = 0; i < M && b; ++i)
	{
		for (int j = 0; j <= i && b; ++j)
		{
			if(attk[j] > fox[i - j]) {
				b = false;
			}
		}
		if(b)
		{
			int s = 0;
			int S = 0;
			for (int j = 0; j <= i; ++j)
			{
				s += attk[j];
				S += fox[j];
			}
			maxdamage = max(maxdamage, S-s);
		}
	}
	if (b && (m > n))
	{
		reverse(fox.begin(), fox.end());
		for (int i = 0; i < def.size(); ++i) {
			if (upper_bound(fox.begin(), fox.end(), def[i]) != fox.end())
			{
				fox.erase(upper_bound(fox.begin(), fox.end(), def[i]));
			} else {
			    b = false;
			}
		}
		
		int siz = attk.size();
		int siz2 = fox.size();
		for (int i = 0; i < siz && b; ++i)
		{
			if(fox[siz2 - i - 1] < attk[siz - i - 1]){
				b = false;
			}
		}
		if (!b)
		{
		    
		} else {
		    int s = 0;
		    for (int i = 0; i < siz; ++i)
		    	s += attk[i];
		    int S = 0;
		    for (int i = 0; i < siz2; ++i)
			    S += fox[i];
		    maxdamage = max(maxdamage, S-s);
		}
	}
	cout << maxdamage;
}