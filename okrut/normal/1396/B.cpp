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
		priority_queue <int> kol;
		rep(i,0,n)
		{
			int a;
			scanf ("%d", &a);
			kol.push(a);
		}
		
		int prv = 0;
		
		int turn = 0;
		while (!kol.empty())
		{
			int c = kol.top();
			kol.pop();
			if (prv>0) kol.push(prv);
			prv = c-1;
			turn^=1;
		}
		
		if (turn==0) printf ("HL\n");
		else printf ("T\n");
	}
	
}