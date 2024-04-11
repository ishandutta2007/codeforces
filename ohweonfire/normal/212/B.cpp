#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int maxn=1000005;
const int HASHSIZE=1048575;
char s[maxn];
int nxt[maxn][26],query[10005],code[maxn][26],n,q;
int num[26],ord[26];
struct hashtable
{
	int head[HASHSIZE+5],key[maxn],next[maxn],cnt;
	int val[maxn];
	inline int& add(int x)
	{
		cnt++;
		next[cnt]=head[x&HASHSIZE];
		head[x&HASHSIZE]=cnt;
		val[cnt]=x;
		key[cnt]=0;
		return key[cnt];
	}
	void clear()
	{
		cnt=0;
		memset(head,0,sizeof(head));
	}
	inline int& operator[](int x)
	{
		for(int i=head[x&HASHSIZE]; i; i=next[i])
			if(x==val[i])
				return key[i];
		return add(x);
	}
	int find(int x)
	{
		for(int i=head[x&HASHSIZE]; i; i=next[i])
			if(x==val[i])
				return true;
		return false;
	}
}ans;
bool cmp(int x,int y)
{
	return num[x]<num[y];
}
int main()
{
	char t[30];
	int ret;
	scanf("%s%d",s,&q);
	n=strlen(s);
	for(int i=1; i<=q; i++)
	{
		scanf("%s",t);
		ret=0;
		for(int j=0; t[j]; j++)
			ret|=(1<<(t[j]-'a'));
		query[i]=ret;
		ans[ret]=1;
	}
	for(int i=n-1; i>=0; i--)
		for(int j=0; j<26; j++)
		{
			if(i==n-1)
			{
				if(s[i]!=j+'a')nxt[i][j]=n;
				else nxt[i][j]=i;
			}
			else
			{
				if(s[i]!=j+'a')nxt[i][j]=nxt[i+1][j];
				else nxt[i][j]=i;
			}
		}
	for(int j=0; j<26; j++)ord[j]=j;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<26; j++)num[j]=nxt[i][j];
		sort(ord,ord+26,cmp);
		int cc=0;
		for(int _=0; _<26; _++)
		{
			if(num[ord[_]]==n)break;
			cc|=(1<<ord[_]);
			code[i][_]=cc;
			if(i==0||code[i][_]!=code[i-1][_])
			{
				if(ans.find(cc))
					ans[cc]++;
			}
		}
	}
	for(int i=1; i<=q; i++)
		printf("%d\n",ans[query[i]]-1);
	return 0;
}