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

int ile['z'+1];
int main ()
{
	string s;
	cin>>s;
	int n = (int)s.size();
	s = s + s;
	int sum=0;
	for (char c = 'a'; c<='z'; c++)
	{
		vector <int> rob;
		rep(i,0,n) if (s[i]==c) rob.pb(i);
		int roz=0, best=0;
		rep(l,1,n)
		{
			memset(ile, 0, sizeof ile);
			roz=0;
			for (int x: rob) 
			{
				//if (ile[s[x+l]]==0) roz++;
				ile[s[x+l]]++;
			}
			for (int t='a'; t<='z'; t++) if (ile[t]==1) roz++;
			best= max(best, roz);
		}
		sum+=best;
	}
	printf ("%.9Lf\n", ld(sum)/ld(n));
}