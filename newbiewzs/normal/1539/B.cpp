#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=100005;
int n,Q;
int sum[N][26];
char s[N];
int main()
{
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		memcpy(sum[i],sum[i-1],sizeof(sum[i]));
		sum[i][s[i]-'a']++;
	}
	while(Q--)
	{
		int l,r,ans=0;
		scanf("%d%d",&l,&r);
		for(int i=0;i<26;i++)ans=(ans+(i+1)*(sum[r][i]-sum[l-1][i]));
		printf("%d\n",ans);
	}
	return 0;
}