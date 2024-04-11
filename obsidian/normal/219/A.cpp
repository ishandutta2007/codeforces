#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
char s[1200];
int ct[120];
int K;
int main()
{
	while(~scanf("%d",&K))
	{
		scanf("%s",s);
		memset(ct,0,sizeof(ct));
		int n=strlen(s);
		for(int i=0;i<n;i++)
		ct[s[i]-'a']++;
		bool can=true;
		for(int i=0;i<26;i++)
		if(ct[i]%K!=0)can=false;
		if(!can)puts("-1");
		else
		{
			for(int i=0;i<K;i++)
			{
				for(int j=0;j<26;j++)
				for(int k=0;k<ct[j]/K;k++)
				printf("%c",j+'a');
			}puts("");
		}
	}
}