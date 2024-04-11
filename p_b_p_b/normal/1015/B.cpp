#include<bits/stdc++.h>
#define sz 100
using namespace std;
char s[sz],t[sz];
int cs[sz],ct[sz],n,cnt;
int ans[40040];
int main()
{
	scanf("%d",&n);
	int i,j,k;
	for (i=1;i<=n;i++) cin>>s[i],cs[s[i]-'a']++;
	for (i=1;i<=n;i++) cin>>t[i],ct[t[i]-'a']++;
	for (i=0;i<26;i++) if (cs[i]!=ct[i]){puts("-1");return 0;}
	for (i=1;i<n;i++)
	{
		for (j=i;s[j]!=t[i];j++);
		for (k=j;k>i;k--) s[k]=s[k-1];
		for (j--;j>=i;j--) ans[++cnt]=j;
	}
	printf("%d\n",cnt);
	for (i=1;i<=cnt;i++) printf("%d ",ans[i]);
}