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
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int a, n, sum[5000], l;
char s[5000];
int m[100005];
long long ans, boo, Sum;

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
    scanf("%d\n", &a);
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
    {
    	if (i != 0)
    		sum[i] = sum[i - 1];
    	sum[i] += s[i] - '0';
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			l = sum[j];
			if (i != 0)
				l -= sum[i - 1];
			if (l <= 1e5)
				m[l]++;
	    	if ((long long) l * (long long) l == a)
	    	{
	    		boo = m[l];
	    	}
	    	Sum++;
		}                  
	ans = -(long long) boo * (long long) boo;
   	if (a == 0)
   	{
   		ans += 2 * Sum * m[0];
   		printf("%I64d\n", ans);
   		return 0;
   	}
   	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			l = sum[j];
			if (i != 0)
				l -= sum[i - 1];
			if (l > 1e5 && a % l == 0)
				ans += 2 * m[a / l];
		}
   	
   	for (int i = 1; i * i <= a; i++)
   	{
   		if (a % i == 0 && (a / i) <= 1e5)
	   	{
	   		ans += 2 * (long long) m[i] * (long long) m[a / i];
   		}
   	}
   	printf("%I64d\n", ans);
	return 0;
}