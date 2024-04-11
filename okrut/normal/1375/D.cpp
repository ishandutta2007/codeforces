#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1004;

int Cnt[N], Tab[N];
int n;

int mex ()
{
	rep(i,0,n+1) if (Cnt[i]==0) return i;
	return -1;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	
	
	rep(q,0,t)
	{
		scanf ("%d", &n);
		rep(i,0,n+1) Cnt[i] = 0;
		rep(i,0,n)
		{
			scanf ("%d", &Tab[i]);
			Cnt[Tab[i]]++;
		}
		
		vector <int> op;
		for (;;)
		{
			for (int m = mex(); m!=n; m = mex())
			{
				Cnt[Tab[m]]--;
				Cnt[m]++;
				Tab[m] = m;
				op.pb(m+1);
			}
			
			assert(mex() == n);
			
			rep(p,0,n) if (Tab[p]!=p)
			{
				Cnt[Tab[p]]--;
				Cnt[n]++;
				Tab[p] = n;
				op.pb(p+1);
				break;
			}
			if (mex()==n) break;
		}
		
		printf ("%d\n", (int)op.size());
		for (int o: op) printf ("%d ", o);
		printf ("\n");
	}
}