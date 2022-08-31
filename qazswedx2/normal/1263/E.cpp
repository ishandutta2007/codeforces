#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
multiset<int> sl,sr;
int n,pt=1000002,lans,rans,lf,rf;
char a[2000005];
void pushl(char ch)
{
	if(ch!='('&&ch!=')') return;
	if(ch=='(')
	{
		lans++;
	}
	else
	{
		sl.insert(lans);
		lans--;
	}
}
void popl(char ch)
{
	if(ch!='('&&ch!=')') return;
	if(ch=='(')
	{
		lans--;
	}
	else
	{
		lans++;
		sl.erase(sl.lower_bound(lans));
	}
}
void pushr(char ch)
{
	if(ch!='('&&ch!=')') return;
	if(ch==')')
	{
		rans++;
	}
	else
	{
		sr.insert(rans);
		rans--;
	}
}
void popr(char ch)
{
	if(ch!='('&&ch!=')') return;
	if(ch==')')
	{
		rans--;
	}
	else
	{
		rans++;
		sr.erase(sr.lower_bound(rans));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf(" %c",&ch);
		if(ch=='L')
		{
			if(pt!=1000002)
			{
				pushr(a[pt]);
				popl(a[pt-1]);
				pt--;
			}
		}
		else if(ch=='R')
		{
			pushl(a[pt]);
			popr(a[pt+1]);
			pt++;
		}
		else a[pt]=ch;
		/*printf("i=%d,lans=%d,rans=%d\n",i,lans,rans);
		for(set<int>::iterator it=sl.begin();it!=sl.end();it++)
			printf("%d ",*it);
		printf("\n");
		for(set<int>::iterator it=sr.begin();it!=sr.end();it++)
			printf("%d ",*it);
		printf("\n");*/
		int fl=rans-lans;
		if(a[pt]=='(') fl--;
		if(a[pt]==')') fl++;
		if((sl.size()&&*sl.begin()<1)||(sr.size()&&*sr.begin()<1)||fl!=0)
			printf("-1 ");
		else
		{
			int tans=0;
			if(sl.size()) tans=max(tans,*(--sl.end()));
			if(sr.size()) tans=max(tans,*(--sr.end()));
			tans=max(tans,max(lans,rans));
			printf("%d ",tans);
		}
	}
	return 0;
}