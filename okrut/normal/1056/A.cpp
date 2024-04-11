#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define miitte (lewy+prawy)/2
#define debug printf
using namespace std;
bitset <1010> possible;
bitset <1010> rob;
int a;
int main ()
{
	int n, r;
	scanf ("%d", &n);
	possible.set();
	rep(p,0,n)
	{
		scanf ("%d", &r);
		rob.reset();
		rep(i,0,r)
		{
			scanf ("%d", &a);
			rob[a]=1;
		}
		possible&=rob;
	}
	rep(i,1,101) if (possible[i]) printf ("%d ", i);
	printf ("\n");
	
}