#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
vector <int> tab, lewo, prawo;
vector <long long> con;
vector <pair <int, int> > rob;
int n;
int main ()
{
	int q, l, r;
	scanf ("%d %d", &n, &q);
	tab.resize(n);
	rep(i,0,n) scanf ("%d", &tab[i]);
	con.resize(n);
	rep(i,1,n) con[i]=abs(tab[i]-tab[i-1]);
	lewo.resize(n, 0);
	prawo.resize(n,0);
	rep(i,1,n)
	{
		while ((rob.size()>0) && (rob.back().fi<=con[i])) rob.pop_back();
		if (rob.size()==0) lewo[i]=0; //jestes najlepszy;
		else lewo[i]=rob.back().se;
		rob.pb(mp(con[i], i));
	}
	rob.clear();
	for (int i=n-1; i>=0; i--)
	{
		while ((rob.size()>0) && (rob.back().fi<con[i])) rob.pop_back();
		if (rob.size()==0) prawo[i]=n; //jestes najlepszy;
		else prawo[i]=rob.back().se;
		rob.pb(mp(con[i], i));
	}
	long long sum=0;
	rep(i,0,q)
	{
		scanf ("%d %d", &l, &r);
		sum=0;
		rep(i,l,r)
		{
			sum+=con[i]*(i-max(lewo[i], l-1))*(min(prawo[i], r)-i);
		}
		cout <<sum <<"\n";
	}
}