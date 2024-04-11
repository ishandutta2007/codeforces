#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 20;
const int inf = N*N;

int Dp[N+1][1<<N], Change[N][N];

int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(q,0,t)
	{
		int n;
		string A, B;
		cin >>n >>A >>B;
		
		rep(i,0,N) rep(j,0,N) Change[i][j] = 0;
		
		bool fail = false;
		rep(i,0,n) if (A[i] > B[i])
		{
			fail = true;
		}
		if (fail)
		{
			cout<<-1<<"\n";
			continue;
		}
		
		rep(i,0,n)
		{
			int a = A[i] - 'a';
			int b = B[i] - 'a';
			Change[a][b] = 1;
		}
		
		/*
		rep(i,0,N)
		{
			rep(j,0,N) debug ("%d ", Change[i][j]);
			debug ("\n");
		}
		*/
		
		int cost = 0;
		rep(a,0,N)
		{
			rep(b,a+1,N) if (Change[a][b]==1) 
			{
				//debug ("From %d to %d\n", a, b);
				rep(c,b+1,N) Change[b][c]|=Change[a][c];
				cost++;
				break;
			}
		}
		cout<<cost <<"\n";
	}
	
	
}