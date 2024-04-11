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
char str[1010];
map<node,int> ma1,ma2,ma,Ma[1010];
map<node,int>::iterator it1,it2;

char operator -(node A,node B)
{
	for (int i=0; i<26; i++)
		if (A.cnt[i]!=B.cnt[i]) return i+'a';
	return '0';
}

node calc(int l,int r)
{
	node Ans=O;
	for (int i=l; i<=r; i++) Ans.cnt[ans[i]-'a']++,Ans.sum++;
	return Ans;
}

bool check(int len)
{
	ma.clear();
	for (int i=1; i<=n-len+1; i++) ma[calc(i,i+len-1)]++;
	for (it2=Ma[len].begin(),it1=ma.begin(); it1!=ma.end(); it1++,it2++)
		if (it2==Ma[len].end()||((*it1).first-(*it2).first)!='0'||(*it1).second!=(*it2).second) return 0;
	return 1;
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
	int nn=n; n=(n+1)>>1;
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
	for (int i=1; i<=n; i++) ans[i]=(f[i]-f[i-1]);
	swap(n,nn);
	printf("? 1 %d\n",n),fflush(stdout);
	for (int i=1; i<=n*(n+1)/2; i++) 
	{
		nw.in(),Ma[nw.sum][nw]++;
		if (nw.sum==n) f[n]=nw;
	}
	int nnn=nn;
	for (int i=0; i<26; i++)
		for (int j=1; j<=f[n].cnt[i]-f[nn].cnt[i]; j++) ans[++nnn]=i+'a';
	for (int i=n; i>nn+1; i--)
	{
		if (check(i-1)) continue;
		for (int j=nn+1; j<i; j++)
		{
			swap(ans[j],ans[i]);
			if (check(i-1)) break;
			swap(ans[j],ans[i]);
		}
	}
	printf("! ");
	for (int i=1; i<=n; i++) putchar(ans[i]);puts("");fflush(stdout);
	return 0;
}