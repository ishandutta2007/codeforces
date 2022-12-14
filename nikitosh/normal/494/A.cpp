#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

int n, ind, bal;
char s[100005];
vector <int> ans;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] == '#')
			ind = i;
	for (int i = 0; i < ind; i++)
		if (s[i] == '#')
		{
			s[i] = ')';
			ans.pb(1);
		}
   	for (int i = 0; i < n; i++)
   		if (s[i] == '(')
   			bal++;
   		else if (s[i] == ')')
			bal--;
	if (bal <= 0)
	{
    	puts("-1");
    	return 0;
    }
	ans.pb(bal);
	bal = 0;
	for (int i = 0; i < ind; i++)
 	{
 		if (s[i] == '(')
   			bal++;
   		else if (s[i] == ')')
			bal--;
		if (bal < 0)
		{
			puts("-1");
			return 0;
		}
	}			
	bal -= ans[(int) ans.size() - 1];
	if (bal < 0)
	{
		puts("-1");
		return 0;
	}
	for (int i = ind + 1; i < n; i++)
	{
 		if (s[i] == '(')
   			bal++;
   		else if (s[i] == ')')
			bal--;
		if (bal < 0)
		{
			puts("-1");
			return 0;
		}
	}			
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d\n", ans[i]);
    return 0;
}