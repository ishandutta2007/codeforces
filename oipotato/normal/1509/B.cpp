#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
char s[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int cnt=0;
		bool flag=1;
		rep(i,n)if(s[i]=='M')
		{
			cnt++;
			if(cnt>i-cnt)flag=0;
		}
		if(cnt!=n/3){puts("NO");continue;}
		cnt=0;
		for(int i=n;i;i--)if(s[i]=='M')
		{
			cnt++;
			if(cnt>n-i+1-cnt)flag=0;
		}
		puts(flag?"YES":"NO");
	}
    return 0;
}