#include <bits/stdc++.h> 
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int INF = 1e6;
int tab[N][5], back[N][5], er[N][5];

void opcja (int p, int s, int del, int from)
{
	int moz = del + tab[p-1][from];
	if (tab[p][s] > moz)
	{
		tab[p][s] = moz;
		back[p][s] = from;
		er[p][s] = del;
	}
} 
int main ()
{
	ios_base::sync_with_stdio(false);
	int tests;
	cin>>tests;
	rep(q,0,tests)
	{
		string s;
		cin>>s;
		int n = s.size();
		s = "#" + s;
		
		rep(i,0,5) tab[0][i] = INF;
		tab[0][0] = 0; //to jest naturalne podejscie
		
		rep(p,1,n+1)
		{
			char c = s[p];
			rep(i,0,5) tab[p][i] = INF;
			//z 0
			//po prostu usun
			rep(i,0,5) opcja(p, i, 1, i); //usuwamy litere
			
			if (c=='o')
			{
				rep(i,0,5) if (i!=4) opcja(p, 1, 0, i);
			}
			else if (c=='n')
			{
				opcja(p, 2, 0, 1);
				rep(i,0,5) if (i!=1) opcja(p, 0, 0, i);
			}
			else if (c=='t')
			{
				rep(i,0,5) opcja(p,3,0,i);
			}
			else if (c=='w')
			{
				opcja(p,4,0,3);
				rep(i,0,5) if (i!=3) opcja(p, 0, 0, i); 
			}
			else
			{
				rep(i,0,5) if (i!=2 || c!='e') opcja(p, 0, 0, i);
			}
			
			//debug ("tab[%d]: ", p);
			//rep(i,0,5) debug ("%d ", tab[p][i]);
			//debug ("\n");
		}
		
		int st = 0;
		rep(i,0,5) if (tab[n][st] > tab[n][i]) st = i;
		
		vector <int> res;
		for (int p = n; p>0; p--)
		{
			if (er[p][st] == 1) res.pb(p);
			st = back[p][st];
		}
		
		cout<<res.size() <<"\n";
		
		for (int x: res) cout<<x <<" ";
		cout<<"\n";
	}
	
}