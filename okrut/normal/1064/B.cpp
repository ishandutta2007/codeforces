#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;

int main ()
{	
	int t, a, x;
	cin>>t;
	rep(qwar,0,t)
	{
		cin>>a;
		x=1;
		while (a>0)
		{
			if (a%2==1) x*=2;
			a/=2;
		}
		cout<<x <<"\n";
	}
}