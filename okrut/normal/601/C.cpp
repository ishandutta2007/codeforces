#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
const int N=100, M=1000;
double p[N*M+1], chan[N*M+2];
int tab[N];
int n, m;
int main ()
{
	scanf ("%d %d", &n, &m);
	if (m==1)
	{
		printf ("1.0\n");
		return 0;
	}
	int sum=0;
	rep(i,0,n) 
	{
		scanf ("%d", &tab[i]);
		sum+=tab[i];
	}
	memset(p, 0.000, sizeof p);
	rep(i,1,m+1) if (tab[0]!=i) p[i]=1.0;
	double d=m-1, q; //mozliwe wyniki
	rep(kon,1,n) //pozostale konkurencje
	{
		memset(chan, 0.000, sizeof chan);
		rep(i,1,m*kon+1) //wszystkie mozliwe wyniki
		{
			q=p[i]/d;
			chan[i+1]+=q;
			chan[i+tab[kon]]-=q;
			chan[i+tab[kon]+1]+=q;
			chan[i+m+1]-=q;
		}
		memset (p, 0.000, sizeof p);
		rep(i,1,m*(kon+1)+1) p[i]=p[i-1]+chan[i];
	}
	double wyn=1;
	rep(i,0,sum) wyn+=p[i];
	printf ("%.12lf\n", wyn);
}

/*
Po kazdej konkurencji: prawd. danego wyniku n*(n*m) - z wyjatkiem wyniku kleofasa
*/