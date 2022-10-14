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


int main ()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	char best = 'z';
	for (char c: s)
	{
		if (best < c)
		{
			cout<<"Ann\n";
		}
		else
		{
			cout<<"Mike\n";
			best = c;
		}
	}
}