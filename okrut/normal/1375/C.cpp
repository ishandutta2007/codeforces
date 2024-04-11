#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e5+10;
int Tab[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		
		vector <int> tab;
		int a;
		scanf ("%d", &a);
		tab.pb(a);
		rep(i,1,n)
		{
			scanf ("%d", &a);
			while (tab.size() >1 and a > tab.back()) tab.pop_back();
			if (a < tab.back()) tab.pb(a);
		}
		if (tab.size()==1) printf ("YES\n");
		else printf ("NO\n");
	}
	
}