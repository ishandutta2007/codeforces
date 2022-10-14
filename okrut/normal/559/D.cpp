#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define ll (long long)
#define debug //
using namespace std;
vector <pair <int, int> > tab;
vector <double> pot, pod; //potegi
int n;
double pkt (int a, int b, bool flag=false)
{
	long long s=0, g;
	g=gcd(abs(tab[a].fi-tab[b].fi), abs(tab[a].se-tab[b].se));
	rep(i,a+1,b) s+=ll(tab[i].fi-tab[a].fi)*ll(tab[i+1].se-tab[a].se)-ll(tab[i+1].fi-tab[a].fi)*ll(tab[i].se-tab[a].se);
	rep(i,a,b) g+=gcd(abs(tab[i+1].fi-tab[i].fi), abs(tab[i+1].se-tab[i].se));
	s=abs(s);
	if (!flag) return (s-g)/2+gcd(abs(tab[a].fi-tab[b].fi), abs(tab[a].se-tab[b].se));
	return (s-g)/2+1; //ale liczone w ll
}
int main ()
{
	scanf ("%d", &n);
	pot.resize(n+1);
	pod.resize(2e3+1);
	pot[0]=1;
	pod[0]=1;
	rep(i,1,n+1) pot[i]=2*pot[i-1];
	rep(i,1,2e3+1) 
	{
		pod[i]=pod[i-1]*0.5;
	}
	tab.resize(n*2+1);
	rep(i,0,n) scanf ("%d %d", &tab[i].fi, &tab[i].se);
	rep(i,0,n+1) tab[i+n]=tab[i];
	double e=0;
	int p=min(60, n-1);
	if (n>=2e3) 
	{
		if (n>=1e3) p-=10;
		if (n>=1e4) p-=20;
		if (n>=1e5) p-=10;
	}
	rep(i,0,n) rep(j,2,p)
	{
		if (n<2e3) e+=pkt(i,i+j)*(pot[n-j-1]-1);
		else e+=pkt(i,i+j)*pod[j+1];
	}
	if (n<2e3) e/=double(pot[n]-1-n-n*((n-1))/2);
	printf ("%.9lf\n", pkt(0,n-1, true)-e);
}