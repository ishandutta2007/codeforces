#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
struct hashtable
{
	int h[maxn],key[maxn],N[maxn];
	LL val[maxn],cnt;
	void clear()
	{
		memset(h,-1,sizeof(h));
		cnt=0;
	}
	void add(LL x)
	{
		int i=abs(x)%maxn;
		N[cnt]=h[i];
		h[i]=cnt;
		val[cnt]=x;
		key[cnt++]=1;
	}
	void inc(LL x)
	{
		int i,j=abs(x)%maxn;
		for(i=h[j];i!=-1;i=N[i])
			if(val[i]==x)
				break;
		if(i!=-1)
			key[i]++;
		else
			add(x);
	}
	int query(LL x)
	{
		int i=abs(x)%maxn;
		for(int j=h[i];j!=-1;j=N[j])
			if(val[j]==x)
				return key[j];
		return 0;
	}
};

hashtable mp;
int v[30];
char s[maxn];
int main()
{
	for(int i=0;i<26;++i)
		scanf("%d",v+i);
	scanf("%s",s+1);
	int n=strlen(s+1);
	long long val,ans=0;
	for(int i=1;i<=n;i++)
		if(v[s[i]-'a']==0)
			ans--;
	for(char t='a';t<='z';++t)
	{
		mp.clear();
		val=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==t)
				mp.inc(val);
			val+=v[s[i]-'a'];
			if(s[i]==t)
				ans+=mp.query(val-v[s[i]-'a']*2);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}