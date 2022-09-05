#include<bits/stdc++.h>
using namespace std;

long long cnt[27][27],ans;
int n,c[27],sum[100010][27];
char s[200010];

int main()
{
	scanf("%s",s),n=strlen(s),ans=0;
	memset(cnt,0,sizeof(cnt)),memset(c,0,sizeof(c));
	for (int i=0; i<n; i++) c[s[i]-'a']++;	
	for (int i=0; i<26; i++) ans=max(ans,(long long)c[i]);
	memset(sum[n],0,sizeof(sum[n]));
	for (int i=n-1; i>=0; i--)
	{
		memcpy(sum[i],sum[i+1],sizeof(sum[i]));
		sum[i][s[i]-'a']++;
	}
	for (int i=0; i<n-1; i++)
		for (int j=0; j<26; j++) cnt[s[i]-'a'][j]+=sum[i+1][j];
	for (int i=0; i<26; i++)
		for (int j=0; j<26; j++) ans=max(ans,cnt[i][j]);
	printf("%I64d\n",ans);
	return 0;
}