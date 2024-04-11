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
int r[20],c[20],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		char s[20];
		scanf("%s",s+1);
		rep(j,m)if(s[j]=='S')r[i]=c[j]=1;
	}
	int ans=0;
	rep(i,n)rep(j,m)if(!r[i]||!c[j])ans++;
	printf("%d\n",ans);
    return 0;
}