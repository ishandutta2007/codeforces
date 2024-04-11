#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

struct F{
	int b,c,id;
}ftd[N],ftc[N],ac[N],ad[N];

int n,c,d,cc,dd,dp[N][21],tc[N],td[N],maxc[N],maxd[N],ans,mc,md;

int lowbit(int x)
{
	return x&-x;
}

bool cmp(F a,F b)
{
	return a.b>b.b;
}

bool cmp2(F a,F b)
{
	return a.c<b.c;
}

bool operator <(F a,F b)
{
	return a.c<b.c;
}

int binsearch(F *x,int l,int r, int val) {
    while(r-l>1) 
	{
        int mid=(l+r)>>1;
        if(x[mid].c<=val) 
            l=mid;
        else 
            r=mid;
    }
    return l;
}

int main()
{
	scanf("%d%d%d",&n,&c,&d);
	for(int i=1;i<=n;i++)
	{
		int b,co;
		char tp[10];
		scanf("%d%d",&b,&co);
		scanf("%s",tp);
		if(tp[0]=='C')
			ftc[++cc].b=b,ftc[cc].c=co;
		else
			ftd[++dd].b=b,ftd[dd].c=co;
	}
	if(cc+dd<2)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=cc;i++)
		ac[i]=ftc[i];
	for(int i=1;i<=dd;i++)
		ad[i]=ftd[i];
	sort(ac+1,ac+cc+1,cmp2);
	sort(ad+1,ad+dd+1,cmp2);
	for(int i=1;i<=cc;i++)
		maxc[i]=max(maxc[i-1],ac[i].b);
	for(int i=1;i<=dd;i++)
		maxd[i]=max(maxd[i-1],ad[i].b);
	for(int i=1;i<=cc;i++)
		if(ftc[i].c<=c)
			mc=max(mc,ftc[i].b);
	for(int i=1;i<=dd;i++)
		if(ftd[i].c<=d)
			md=max(md,ftd[i].b) ;
	if(mc&&md)
		ans=mc+md;
	for(int i=2;i<=cc;i++)
	{
		if(ac[i].c<=c)
		{
			F a;
			a.c=c-ac[i].c;
			int r=binsearch(ac,0,i,a.c);
			if(r)
				ans=max(ans,ac[i].b+maxc[r]);
		}
	}
	for(int i=2;i<=dd;i++)
	{
		if(ad[i].c<=d)
		{
			F a;
			a.c=d-ad[i].c;
			int r=binsearch(ad,0,i,a.c);
			if(r)
				ans=max(ans,ad[i].b+maxd[r]);
		}
	}
 	printf("%d",ans);
}
/*
6 4 9
6 6 D
1 4 D
6 7 C
7 6 D
5 7 D
2 5 D
*/