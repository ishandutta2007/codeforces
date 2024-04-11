#include<cstdio>
#include<cstring>

char s[1001][101],ss[101];
int a[1001][26],n,m,t[101];
bool b[26],bo[1001],ans[26],aa[26];

int main()
{
	scanf("%d",&n);
	scanf("%s",&ss); t[0]=0;
	memset(b,1,sizeof(b));
	memset(ans,1,sizeof(ans));
	for (int i=0; i<n; i++)
		if (ss[i]=='*') t[++t[0]]=i;
		else b[ss[i]-'a']=0;
	scanf("%d",&m); 
	for (int i=1; i<=m; i++)
	{
		scanf("%s",&s[i]); bo[i]=1;
		for (int j=1; j<=t[0]; j++)
			if (!b[s[i][t[j]]-'a']) bo[i]=0;
		for (int j=0; j<n; j++)
			if (ss[j]!='*'&&ss[j]!=s[i][j]) bo[i]=0;
	}
	for (int i=1; i<=m; i++)
		if (bo[i])
		{
			memset(aa,0,sizeof(aa));
			for (int j=1; j<=t[0]; j++) aa[s[i][t[j]]-'a']=1;
			for (int j=0; j<26; j++) 
				if (!aa[j]) ans[j]=0;
		}
	int anss=0;
	for (int i=0; i<26; i++)
		if (ans[i]) anss++;
	printf("%d\n",anss);
	return 0;
}