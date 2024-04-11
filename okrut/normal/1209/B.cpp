#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

bitset <100> rob;
int A[100], B[100];
const int M = 1e4;
vector <int> tog[M];

int main ()
{
	rob.reset();
	int n;
	scanf ("%d", &n);
	string s;
	cin>>s;
	rep(i,0,n) 
	{
		if (s[i]=='1') rob[i] = 1;
	}
	int best = 0;
	best = max(best, (int)rob.count());
	int a, b;
	rep(i,0,n)
	{
		scanf ("%d %d", &a, &b);
		while (b < M)
		{
			tog[b].pb(i);
			b+=a;
		}
	}
	
	
	rep(t,0,M)
	{
		best = max(best, (int)rob.count());
		for (int p: tog[t]) 
		{
			if (rob[p]) rob[p] = 0;
			else rob[p] = 1;
		}
	}
	printf ("%d\n", best);
}