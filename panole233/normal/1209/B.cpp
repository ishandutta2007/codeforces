#include<bits/stdc++.h>
using namespace std;

int cnt[1010],n,a,b;
char s[1010];

int main()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n),scanf("%s",s);
	for (int i=0; i<n; i++)
	{
		scanf("%d%d",&a,&b);
		for (int j=0; j<=1000; j++)
			if ((s[i]-'0')^(j>=b&&(!(((j-b)/a)&1)))) cnt[j]++;
	}
	int ans=0;
	for (int i=0; i<=1000; i++) ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}