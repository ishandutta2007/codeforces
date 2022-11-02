#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstring>
#include<bitset>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
bitset<100001> b[30],tmp;
int n,q;
char s[100010],s1[100010];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		b[s[i]-'a'].set(i);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int x;
			char c;
			scanf("%d %c",&x,&c);
			b[s[x-1]-'a'].reset(x-1);
			s[x-1]=c;
			b[s[x-1]-'a'].set(x-1);
		}
		else
		{
			int l,r;
			scanf("%d%d%s",&l,&r,s1);
			int len=strlen(s1);
			if(r-l+1<len)
			{
				puts("0");
				continue;
			}
			tmp.set();
			for(int j=0;j<len;j++)
			{
				tmp&=b[s1[j]-'a']>>j;
			}
			printf("%d\n",(tmp>>(l-1)).count()-(tmp>>(r+1-len)).count());
		}
	}
	return 0;
}