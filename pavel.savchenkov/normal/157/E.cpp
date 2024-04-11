//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
const i64 mod = 1000000007;
using namespace std;
char s[150];
int t;
i64 d[26*100+200][130];



int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d\n",&t);
  memset(d,0,sizeof(d));
  
  for (int num=0; num <= 120; num++)
   for (int sum=0; sum <= 26*100 + 100; sum++)
	{
		if (num == 0) { if (sum==0) d[sum][num]=1; else break; }
		else 
			for (int last = 0; last < 26; last++)
				if (sum - last >= 0) d[sum][num] = (d[sum][num] + d[sum-last][num-1]) % mod;
	}
	
	
  forn(it,t)
  {
	  gets(s);
	  int n = (int)strlen(s);
	  int sum = 0;
	  forn(i,n) sum += s[i] - 'a';
	  printf("%I64d\n",(d[sum][n]==0)?1000000006:(d[sum][n]-1));
  }
  
  
  return 0;
}