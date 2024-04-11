#include<bits/stdc++.h>
using namespace std;

char s[1010],ans[1010];

struct node
{
	int cnt[26],sum;
	void in()
	{
		scanf("%s",s); int len=strlen(s);
		memset(cnt,0,sizeof(cnt)),sum=len;
		for (int i=0; i<len; i++) cnt[s[i]-'a']++;
	}
}nw,f[1010],O;

bool operator <(node A,node B)
{
	for (int i=0; i<26; i++)
		if (A.cnt[i]!=B.cnt[i])
		{
			if (A.cnt[i]<B.cnt[i]) return 1;
			return 0;
		}
	return 0;
}

int n;
map<node,int> ma1,ma2;
map<node,int>::iterator it1,it2;

char operator -(node A,node B)
{
	for (int i=0; i<26; i++)
		if (A.cnt[i]!=B.cnt[i]) return i+'a';
	return '0';
}

int main()
{
	for (int i=0; i<26; i++) O.cnt[i]=0;
	O.sum=0,f[0]=O;
	scanf("%d",&n);
	if (n<=3)
	{
		for (int i=1 ;i<=n; i++)
		{
			printf("? %d %d\n",i,i),fflush(stdout);
			scanf("%s",s),ans[i]=s[0];
		}
		printf("! ");
		for (int i=1 ;i<=n; i++) putchar(ans[i]);
		return puts(""),0;
	}
	printf("? 1 %d\n",n),ma1.clear(),ma2.clear(),fflush(stdout);
	for (int i=1; i<=n*(n+1)/2; i++) nw.in(),ma1[nw]++;
	printf("? 2 %d\n",n),fflush(stdout);
	for (int i=1; i<=n*(n-1)/2; i++) nw.in(),ma2[nw]++;
	for (it2=ma2.begin(),it1=ma1.begin(); it1!=ma1.end(); it1++)
	{
		if (it2==ma2.end()||((*it2).first-(*it1).first)!='0')
		{
			f[(*it1).first.sum]=(*it1).first;
		} else 
		{
			if ((*it1).second!=(*it2).second) f[(*it1).first.sum]=(*it1).first;
			it2++;
		}
	}
	printf("! ");
	for (int i=1; i<=n; i++) putchar(f[i]-f[i-1]);
	puts("");
	return 0;
}