#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

//wiadomo ile
string s;
vector <vector <int> > ciag;
vector <int> jed, zer;
int main ()
{
	cin>>s;
	int n = s.size();
	int z=0, j=0;
	for (char c: s) if (c=='0') z++;
					else j++;
	
	int k = z - j;
	bool blad = false;
	if (k<0) 
	{
		printf ("-1\n");
		return 0;
	}
	ciag.resize(k);
	
	int p=0;
	for (char c: s) 
	{
		p++;
		if (c=='0')
		{
			if (k>0) 
			{
				zer.pb(--k);
				ciag[k].pb(p);
			}
			else
			{
				if (jed.empty()) blad = true;
				else 
				{
					int x = jed.back();
					jed.pop_back();
					zer.pb(x);
					ciag[x].pb(p);
				}
			}
		}
		else
		{
			if (zer.empty()) blad = true;
			else
			{
				int x = zer.back();
				zer.pop_back();
				jed.pb(x);
				ciag[x].pb(p);
			}
		}
	}
	if (blad)
	{
		printf ("-1\n");
		return 0;
	}
	printf ("%d\n", (int)ciag.size());
	for (auto v: ciag) 
	{
		printf ("%d ", (int) v.size());
		for (int x: v) printf ("%d ", x);
		printf ("\n");
	}
}