#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
using namespace std;
int n,s[2],s1[2];
char a[100010],b[100010];
int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(int i=1;i<=n;i++)if(b[i]=='0')s[a[i]-'0']++;else s1[a[i]-'0']++;
	printf("%lld\n",1ll*s[0]*s1[1]+1ll*s[1]*s1[0]+1ll*s[0]*s[1]);
	return 0;
}