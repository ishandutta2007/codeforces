#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

vector <int> r1, r2;

int f1, f2, l1, l2;
int n;
bool ok ()
{
	rep(i,0,n-1) if (r1[i]!=r2[i]) return false;
	return (f1==f2 && l1==l2);
}


int main ()
{
	scanf ("%d", &n);
	
	int a, b;
	scanf ("%d", &a);
	
	f1 = a;
	rep(i,1,n)
	{
		scanf ("%d", &b);
		r1.pb(a - b);
		a = b;
	}
	l1 = a;
	
	scanf ("%d", &a);
	
	f2 = a;
	rep(i,1,n)
	{
		scanf ("%d", &b);
		r2.pb(a - b);
		a = b;
	}
	l2 = a;
	
	sort(r1.begin(), r1.end());
	sort(r2.begin(), r2.end());
	
	if (ok()) printf ("Yes\n");
	else printf ("No\n");
}