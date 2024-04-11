#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e4;
int A[N];

bool solve (int n)
{
	int sum = 0;
	rep(i,1,n+1) sum+=A[i];
	if (sum % n != 0) return false;
	int avg = sum/n;
	
	vector <int> I, J, X;
	
	rep(i,2,n+1)
	{
		if (A[i]%i!=0)
		{
			I.pb(1);
			J.pb(i);
			X.pb(i - A[i]%i);
			
			A[i] += i - A[i]%i;
		}
		
		I.pb(i);
		J.pb(1);
		X.pb(A[i]/i);
	}
	
	rep(i,2,n+1)
	{
		I.pb(1);
		J.pb(i);
		X.pb(avg);
	}
	
	printf ("%d\n", (int)I.size());
	rep(a,0,(int)I.size()) printf ("%d %d %d\n", I[a], J[a], X[a]);
	return true;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		rep(i,1,n+1) scanf ("%d", &A[i]);
		
		if (!solve(n)) printf ("-1\n");
	}
	
}