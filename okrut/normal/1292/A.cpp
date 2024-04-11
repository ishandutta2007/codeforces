#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+10;

int Tab[N][2];

/* from x to x+1 */
bool pass (int x)
{
	return ((Tab[x][0]==0 and Tab[x+1][0]==0) or (Tab[x][1]==0 and Tab[x+1][1]==0));
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	set <int> notPass;
	int n, q;
	scanf ("%d %d", &n, &q);
	
	rep(i,0,q)
	{
		int r, c;
		scanf ("%d %d", &r, &c);
		r--; 
				
		Tab[c][r]^=1;
		
		if (c<n)
		{
			if (pass(c)) notPass.erase(c);
			else notPass.insert(c);
		}
		
		if (c>1) 
		{
			if (pass(c-1)) notPass.erase(c-1);
			else notPass.insert(c-1);
		}
		
		if (notPass.size()==0) printf ("Yes\n");
		else printf ("No\n");
	}
	
}