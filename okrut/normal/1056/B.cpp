#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define miitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
vector <ll> ile;

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	ile.resize(m+1,0);
	rep(i,1,m+1) 
	{
		ile[i]=n/m;
		if (i<=n%m) ile[i]++; 
	}
	ll res=0;
	rep(i,1,m+1) rep(j,1,m+1) if ((i*i+j*j)%m==0)
	{
		res+=ile[i]*ile[j];
	}
	printf ("%lld\n", res);
}