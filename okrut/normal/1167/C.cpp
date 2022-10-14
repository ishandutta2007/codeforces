#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

vector <int> ojce;
vector <int> wagi;
int krol (int a)
{
	if (ojce[a]==-1) return a;
	ojce[a] = krol(ojce[a]);
	return ojce[a];
}
bool unia (int a, int b)
{
	int krola = krol(a), krolb = krol(b);
	if (krola==krolb) return false;
	wagi[krola]+=wagi[krolb];
	ojce[krolb] = krola;
	return true;
}
int n, m;
int main ()
{
	scanf ("%d %d", &n, &m);
	ojce.resize(n+m+1, -1);
	wagi.resize(n+1+m, 0);
	rep(i,1,n+1) wagi[i]=1;
	int k, a;
	rep(i,n+1,n+m+1)
	{
		scanf ("%d", &k);
		rep(j,0,k) 
		{
			scanf ("%d", &a);
			unia(i, a);
		}
	}
	rep(i,1,n+1) printf ("%d ", wagi[krol(i)]);
	printf ("\n");
}