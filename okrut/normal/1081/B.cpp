#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

vector <vector <int> > moc;
vector <int> res;
int main ()
{
	int n;
	int a;
	scanf ("%d", &n);
	moc.resize(n+1);
	res.resize(n, -1); //nwm
	rep(i,0,n)
	{
		scanf ("%d", &a);
		moc[n-a].pb(i);
	}
	int x=1, m;
	rep(i,1,n+1)
	{
		m=moc[i].size();
		if (m%i!=0)
		{
			printf ("Impossible\n");
			return 0;
		}
		rep(j,0,m/i)
		{
			rep(l,0,i) res[moc[i][j*i+l]]=x;
			x++;
		}
	}
	printf ("Possible\n");
	rep(i,0,n) printf ("%d ", res[i]);
	printf ("\n");
}