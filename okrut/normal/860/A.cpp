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

bool cons (char c)
{
	return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main ()
{
	string s;
	cin>>s;
	string ans;
	int n = 0;
	for (char c: s)
	{
		if (cons(c))
		{
			n++;
			if (n>=3 && !(ans.back()==c && ans[(int)ans.size()-2]==c))
			{
				n = 1;
				ans.pb(' ');
			}
		}
		else
		{
			n = 0;
		}
		ans.pb(c);
	}
	cout<<ans <<"\n";
}