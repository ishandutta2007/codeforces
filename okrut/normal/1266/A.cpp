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
	int n;
	cin>>n;
	rep(i,0,n)
	{
		string s;
		cin>>s;
		int sum = 0;
		bool zer = false;
		bool par = false;
		
		for (char c: s)
		{
			int x = c - '0';
			sum+=x;
			if (x==0 && !zer)
			{
				zer = true;
			}
			else if (x%2==0)
			{
				par = true;
			}
		}
		
		if (sum==0 || ( zer and par and sum%3==0)) cout<<"red\n";
		else cout <<"cyan\n";
	}
}