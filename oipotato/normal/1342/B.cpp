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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char t[110],s[210];
		scanf("%s",t+1);
		int n=strlen(t+1);
		bool flag=1;
		rep(i,n)if(t[i]!=t[1])flag=0;
		if(flag)puts(t+1);
		else
		{
			int cnt=0;
			rep(i,n)
			{
				s[++cnt]=t[i];
				if(i<n&&t[i]==t[i+1])s[++cnt]=t[i]=='0'?'1':'0';
			}
			s[cnt+1]=0;
			puts(s+1);
		}
	}
    return 0;
}