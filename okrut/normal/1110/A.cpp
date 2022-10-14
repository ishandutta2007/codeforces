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



int main ()
{
	int k, b;
	scanf ("%d %d", &b, &k);
	b%=2;
	int mod=0, a;
	rep(i,0,k-1)
	{
		scanf ("%d", &a);
		mod+=b * (a % 2);
	}
	scanf ("%d", &a);
	mod+=a;
	if (mod%2==1) printf ("odd\n");
	else printf ("even\n");
}