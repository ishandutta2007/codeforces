#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
vector <pair <int, int> > tab;
vector <int> ile;
int n, m, k;
int main ()
{
	int a, b;
	string tekst;
	cin>>tekst;
	n=tekst.size();
	ile.resize(n, 0);
	tab.resize(n, mp(0,0));
	rep(i,0,n) if (tekst[i]=='0') ile[i]++;
	cin>>tekst;
	rep(i,0,n) if (tekst[i]=='0') ile[i]++;
	if (n==1)
	{
		printf ("0\n");
		return 0;
	}
	tab[0]=mp(0,ile[0]);
	rep(i,1,n)
	{
		tab[i]=mp(tab[i-1].fi, ile[i]);
		if (tab[i-1].se==2) if (ile[i]>0) 
		{
			tab[i].fi++;
			tab[i].se=ile[i]-1;
		}
		if (tab[i-1].se==1) if (ile[i]==2)
		{
			tab[i].fi++;
			tab[i].se=0;
		}
	}
	printf ("%d\n", tab[n-1].fi);
}