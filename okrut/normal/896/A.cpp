#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug // 
using namespace std;
typedef long long ll;
typedef long double ld;

const char *Pref = "What are you doing while sending \"";
const char *Inf = "\"? Are you busy? Will you send \"";
const char *Suf = "\"?";
const char *F0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

const ll inf = 1e18+100;

const int N = 1e5+5;
ll Len[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int PLen = strlen(Pref);
	int ILen = strlen(Inf);
	int SLen = strlen(Suf);
	int FLen = strlen(F0);
	Len[0] = FLen;
	rep(i,1,N) 
	{
		Len[i] = PLen + Len[i-1] + ILen + Len[i-1] + SLen;
		if (Len[i] >= inf) Len[i] = inf;
	}
	
	int q;
	scanf ("%d", &q);
	rep(d,0,q)
	{
		int n;
		ll k;
		scanf ("%d %lld", &n, &k);
		
		debug ("Lens (%d %d %d): ", PLen, ILen, SLen);
		rep(i,0,4) debug ("%lld ", Len[i]);
		debug ("\n");
		
		if (k > Len[n]) printf (".");
		else for (;;)
		{
			debug ("n= %d: I have k = %lld\n", n, k);
			if (n==0) 
			{
				printf ("%c", F0[k-1]);
				break;
			}
			if (k <= PLen)
			{
				debug ("I have k = %lld\n", k);
				printf ("%c", Pref[k-1]);
				break;
			}
			k-=PLen;
			if (k <= Len[n-1])
			{
				n--;
				continue;
			}
			k -= Len[n-1];
			if (k<= ILen)
			{
				debug ("I have k = %lld\n", k);
				printf ("%c", Inf[k-1]); 
				break;
			}
			k -= ILen;
			if (k<= Len[n-1])
			{
				debug ("I have k = %lld\n", k);
				n--;
				continue;
			}
			k -= Len[n-1];
			
			assert( k<=SLen);
			
			printf ("%c", Suf[k-1]);
			break;
		}
	}
	printf ("\n");
}