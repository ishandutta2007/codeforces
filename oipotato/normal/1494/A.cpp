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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char s[55];
		scanf("%s",s+1);
		int n=strlen(s+1),f[55];
		if(s[1]==s[n]){puts("NO");continue;}
		int a=0,b=0;
		rep(i,n)f[i]=0;
		rep(i,n)if(s[i]==s[1])f[i]=1,a++;
		rep(i,n)if(s[i]==s[n])f[i]=-1,b++;
		if(a==n/2){rep(i,n)if(!f[i])f[i]=-1;}
		else if(b==n/2){rep(i,n)if(!f[i])f[i]=1;}
		else{puts("NO");continue;}
		int now=0;
		bool flag=1;
		rep(i,n)
		{
			now+=f[i];
			if(now<0)flag=0;
		}
		puts(flag?"YES":"NO");
	}
    return 0;
}