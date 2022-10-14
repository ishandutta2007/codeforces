#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 305;
int Pref[N][N], Rnk[N][N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	
	rep(i,0,n+1) rep(j,0,n) 
	{
		scanf ("%d", &Pref[i][j]);
		Rnk[i][Pref[i][j]] = n-j;
	}
	
	rep(i,0,n)
	{
		int Abest = -1;
		int Arank = -1;
		
		int Btime = 0;
		int Brank = -1;
		
		rep(j,1,n+1) if (j!=i+1)
		{
			if (Abest==-1 or Arank < Rnk[n][j]) 
			{
				Abest = j;
				Arank = Rnk[n][j];
			}
			
			if (Rnk[i][Abest] > Brank)
			{
				Brank  = Rnk[i][Abest];
				Btime = Abest;
			}
		}
		
		printf ("%d ", Btime);
		
	}
	printf ("\n");
	
}