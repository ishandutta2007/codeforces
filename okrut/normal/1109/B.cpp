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

bool pal (string &s)
{
	int a = 0, b = (int)s.size()-1;
	while (a<b)
	{
		if (s[a]!=s[b]) return false;
		a++;
		b--;
	}
	return true;
}

int main ()
{
	int n;
	string s;
	cin>>s;
	n = s.size();
	if (n<=3)
	{
		printf ("Impossible\n");
		return 0;
	}
	
	bool ok = false;
	rep(i,1,n/2) if (s[i]!=s[i-1]) ok = true;
	if (!ok)
	{
		printf ("Impossible\n");
		return 0;
	}
	//sprawdzamy 1
	//how to do cyclic shifts
	rep(i,0,n)
	{
		string b;
		rep(j,i,n) b.pb(s[j]);
		rep(j,0,i) b.pb(s[j]);
		if (b==s) continue;
		if (pal(b))
		{
			printf ("1\n");
			return 0;
		}
	}
	printf ("2\n");
}