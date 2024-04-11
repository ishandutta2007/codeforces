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

string s;
int main ()
{
	cin>>s;
	int w=0, h=0;
	rep(i,0,(int)s.size())
	{
		if (s[i]=='1')
		{
			if (w==0)
			{
				printf ("1 1\n");
				w++;
			}
			else
			{
				printf ("1 3\n");
				w=0;
			}
		}
		if (s[i]=='0')
		{
			if (h==0)
			{
				printf ("3 4\n");
				h++;
			}
			else
			{
				printf ("1 4\n");
				h=0;
			}
		}
	}
}