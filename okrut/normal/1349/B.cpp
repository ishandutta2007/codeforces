#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std; 
typedef long long ll;
typedef long double ld;

void solve (int n, vector <int> &A)
{
		rep(i,1,n) if (A[i]==0 and A[i-1]==0) 
		{
			printf ("yes\n");
			return;
		}
		
		rep(i,1,n-1) if (A[i-1]==0 and A[i+1]==0)
		{
			printf ("yes\n");
			return;
		}
		printf ("no\n");
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, k;
		scanf ("%d %d", &n, &k);
		vector <int> A(n);
		for (int &a: A) scanf ("%d", &a);
		bool is = false;
		for (int &a: A)
		{
			if (a==k) is= true;
			if (a>=k) a = 0;
			else a = -1;
		}
		
		if (!is)
		{
			printf ("no\n");
			continue;
		}
		
		if (n==1) printf ("yes\n");
		else solve(n,A);
		
	}
}