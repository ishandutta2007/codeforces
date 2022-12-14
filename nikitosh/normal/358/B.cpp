#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int N, len, sz, l;
char s[500005], t[500005], r[500005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d\n", &N);
	s[sz++] = '<';
	s[sz++] = '3';
	for (int i = 0; i < N; i++)
	{
		gets(t);
		len = strlen(t);
		for (int i = 0; i < len; i++)
			s[sz++] = t[i];
		s[sz++] = '<';
		s[sz++] = '3';
    }
    //puts(s);
    gets(r);
    len = strlen(r);
    l = 0;
    for (int i = 0; i < sz; i++)
    {
    	while(l != len && r[l] != s[i])
    		l++;	
    	if (l == len)
    	{
    		puts("no");
    		return 0;
    	}
    	l++;
    }
    puts("yes");
    return 0;
}