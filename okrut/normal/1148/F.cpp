#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define debug //
using namespace std;
typedef long long ll;
const int N = 3e5;
ll val[N], mask[N]; 
int fliped[N];

int main ()
{
	memset (fliped, 0, sizeof fliped);
	int n;
	scanf ("%d", &n);
	rep(i,0,n) scanf ("%lld %lld", &val[i], &mask[i]);
	
	ll sum=0LL;
	rep(i,0,n) sum+=val[i];
	debug ("sum : %lld\n", sum);
	if (sum>0LL) 
	{
		rep(i,0,n) val[i]*=-1LL;
		sum*=-1LL;
	}
	
	ll jed, zer;
	ll res = 0LL;
	rep(k,0,62)
	{
		jed = 0LL;
		zer = 0LL;
		//jak bardzo chce byc zerem, a jak jedynka
		rep(i,0,n) if ((mask[i] & (1LL<<k) && mask[i] < (1LL<<(k+1))))
		{
			if ((val[i]<0LL && fliped[i]==1) || (val[i]>0LL && fliped[i]==0)) 
			{
				debug ("%lld wanna stay\n", mask[i]);
				zer+=abs(val[i]); //jest ok
			}
			
			if ((val[i]>0LL && fliped[i]==1) || (val[i]<0LL && fliped[i]==0)) 
			{
				debug ("%lld wanna flip\n", mask[i]);
				jed+=abs(val[i]); // I wanna flip
			}
		}
		
		debug ("bit %d: %lld %lld\n", k, zer, jed);
		if (jed> zer) 
		{
			rep(i,0,n) if (mask[i] & (1LL <<k)) fliped[i] = 1 - fliped[i];
			res+= (1LL <<k);
		}
	}
	
	ll sum2=0LL;
	rep(i,0,n) 
	{
		debug ("%d-th: %d\n", i, __builtin_popcount(mask[i] & res) % 2);
		if (__builtin_popcount(mask[i] & res) % 2==1) sum2-=val[i];
		else sum2+=val[i];
	}
	
	//assert(sum2 > 0LL);
	
	printf ("%lld\n", res);
}