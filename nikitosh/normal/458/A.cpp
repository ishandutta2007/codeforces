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

const int MAXL = 200000;

char s[100005], t[100005];
int len1, len2, a[200005], b[200005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	gets(s);
	gets(t);
	len1 = strlen(s);
	len2 = strlen(t);	    
    for (int i = 0; i < len1; i++)
    	a[i] = s[i] - '0';
    for (int i = 0; i < len2; i++)
    	b[i] = t[i] - '0';
    reverse(a, a + len1);
    reverse(b, b + len2);
	for (int i = len1 - 1; i > 0; i--)
	{
	    if (a[i] == 1 && a[i - 1] == 1)
		{
			a[i + 1] = 1;
			a[i] = 0;
			a[i - 1] = 0;
			i += 3;
    	} 
	}
	for (int i = len2 - 1; i > 0; i--)
		if (b[i] == 1 && b[i - 1] == 1)
		{
			b[i + 1] = 1;
			b[i] = 0;
			b[i - 1] = 0;
			i += 3;
    	} 
    for (int i = MAXL; i >= 0; i--)
    {
    	if (a[i] > b[i])
    	{
    		puts(">");
    		return 0;
    	}
    	if (a[i] < b[i])
    	{
    		puts("<");
    		return 0;
    	}
    }
    puts("=");
    return 0;
}