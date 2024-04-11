#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;

int main ()
{
	int n, maks=0, a;
	long long sum=0;
	scanf ("%d", &n);
	rep(i,0,n) 
	{
		scanf ("%d", &a);
		sum+=a;
		maks=max(maks, a);
	}
	while (sum*2>=maks*n) maks++;
	printf ("%d\n", maks);
}