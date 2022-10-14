#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		vector <int> A(n);
		for (int &a: A) scanf ("%d", &a);
		int sum = 0;
		for (int a: A) sum+=a;
		if (sum==0)
		{
			printf ("NO\n");
			continue;
		}
		
		sort(A.begin(), A.end());
		if (sum>0) reverse(A.begin(), A.end());
		
		printf ("YES\n");
		for (int a: A) printf ("%d ", a);
		printf ("\n");
	}
	
}