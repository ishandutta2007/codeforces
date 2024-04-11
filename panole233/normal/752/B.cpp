#include<cstdio>
#include<cstring>

char s1[10001],s2[10001];
bool bo[26];
int ch[26];

int main()
{
	scanf("%s%s",&s1,&s2);
	int len=strlen(s1);
	memset(ch,255,sizeof(ch));
	for (int i=0; i<len; i++)
	{
		if (ch[s1[i]-'a']==-1&&ch[s2[i]-'a']==-1)
		{
			ch[s1[i]-'a']=s2[i]-'a'; ch[s2[i]-'a']=s1[i]-'a';
		} else
		if (ch[s1[i]-'a']!=s2[i]-'a'||ch[s2[i]-'a']!=s1[i]-'a') {printf("-1"); return 0;}
	}
	int ans=0;
	for (int i=0; i<26; i++)
		if (ch[i]!=i&&ch[i]!=-1) ans++;
	printf("%d\n",ans/2);
	memset(bo,0,sizeof(bo));
	for (int i=0; i<26; i++)
		if (ch[i]!=i&&ch[i]!=-1&&!bo[i]) bo[ch[i]]=1,printf("%c %c\n",i+'a',ch[i]+'a');
	return 0;
}