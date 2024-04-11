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
		char s[410],t[410];
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		int len=n*m/__gcd(n,m);
		for(int i=n+1;i<=len;i++)s[i]=s[i-n];
		for(int i=m+1;i<=len;i++)t[i]=t[i-m];
		s[len+1]=0;
		bool flag=1;
		rep(i,len)if(s[i]!=t[i]){flag=0;break;}
		if(!flag)puts("-1");else puts(s+1);
	}
    return 0;
}