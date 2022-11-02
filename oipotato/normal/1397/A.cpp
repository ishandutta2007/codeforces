#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
char s[1010];
int c[30];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,26)c[i]=0;
		rep(i,n)
		{
			scanf("%s",s);
			int len=strlen(s);
			rep(j,len)c[s[j-1]-'a'+1]++;
		}
		bool flag=1;
		rep(i,26)if(c[i]%n){flag=0;break;}
		puts(flag?"YES":"NO");
	}
	return 0;
}