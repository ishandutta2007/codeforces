#include<bits/stdc++.h>
using namespace std;

bool bo[26];
int n,T,sum[200010][26],la[27];
char s[200010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s+1),n=strlen(s+1);
		memset(sum[0],0,sizeof(sum[0]));
		for (int i=1; i<=n; i++)
			for (int j=0; j<26; j++) sum[i][j]=sum[i-1][j]+(s[i]==('a'+j));
		for (int j=0; j<26; j++) bo[j]=(sum[n][j]!=0),la[j]=-1;
		bool BO=1;
		for (int i=1; i<=n; i++)
		{
			int j=s[i]-'a';
			if (la[j]!=-1)
			{
				for (int k=0; k<26; k++)
					if (bo[k]&&sum[i][k]==sum[la[j]][k]) {BO=0; break;}
			}
			la[j]=i;
			if (!BO) break;
		}
		puts(BO?"YES":"NO");
	}
	return 0;
}