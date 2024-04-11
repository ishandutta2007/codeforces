#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		if((s[n]-'0')%2==0)puts("0");
		else if((s[1]-'0')%2==0)puts("1");
		else
		{
			bool flag=0;
			rep(i,n)if((s[i]-'0')%2==0){flag=1;break;}
			puts(flag?"2":"-1");
		}
	}
    return 0;
}