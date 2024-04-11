#include<bits/stdc++.h>
using namespace std;

int n,L;
long long limpl,limpr,limml,limmr,X,Y;
struct node{long long k,b,x,y;}a[200010];

long long getabs(long long x) {return (x<0)?(-x):x;}
bool cmp(const node &a,const node &b) {return a.b<b.b;}

int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1; i<=n; i++)
	{
		scanf("%I64d%I64d%I64d",&a[i].b,&a[i].x,&a[i].y);
		a[i].k=a[i].b/L,a[i].b%=L;
	}
	sort(a+1,a+1+n,cmp);
	a[0].k=a[0].b=a[0].x=a[0].y=0,a[n+1]=a[0],a[n+1].b=L,a[n+1].k=-1;
	limpl=-L,limpr=L,limml=-L,limmr=L;
	for (int i=0; i<=n; i++)
	{
		if (a[i].k==a[i+1].k) 
		{
			if (getabs(a[i].x-a[i+1].x)+getabs(a[i].y-a[i+1].y)>a[i+1].b-a[i].b)
				return puts("NO"),0;
			continue;
		}
		long long k=a[i+1].k-a[i].k,x=a[i].x-a[i+1].x,y=a[i].y-a[i+1].y,b=a[i+1].b-a[i].b,lim,l;
		if (k<0) k=-k,x=-x,y=-y;
		l=(b-x-y)/k;
		if (l<limpl-1) return puts("NO"),0;
		for (int j=l-1; j<=l+1; j++) if (k*j<=b-x-y) lim=j;
		if (lim<limpr) limpr=lim;
		l=(y-x-b)/k;
		if (l>limmr+1) return puts("NO"),0;
		for (int j=l+1; j>=l-1; j--) if (k*j>=y-x-b) lim=j;
		if (lim>limml) limml=lim;
		l=(b-x+y)/k;
		if (l<limml-1) return puts("NO"),0;
		for (int j=l-1; j<=l+1; j++) if (k*j<=b-x+y) lim=j;
		if (lim<limmr) limmr=lim;
		l=(-b-x-y)/k;
		if (l>limpr+1) return puts("NO"),0;
		for (int j=l+1; j>=l-1; j--) if (k*j>=-b-x-y) lim=j;
		if (lim>limpl) limpl=lim;
	}
	int ga=0;
	if (limpl>limpr||limml>limmr||limpl==limpr&&limml==limmr&&(limpl&1)!=(limml&1)) return puts("NO"),0;
	if ((limpl&1)!=(limml&1)) {if (limpl<limpr) limpl++,ga=1; else limml++,ga=2;}
	X=(limpl+limml)/2; Y=(limpl-limml)/2;
	for (int i=1; i<=n+1; i++) a[i].x-=a[i].k*X,a[i].y-=a[i].k*Y;
	bool bo=0;
	for (int i=0; i<=n; i++)
		if (((a[i+1].b-a[i].b)&1)!=((getabs(a[i+1].x-a[i].x)+getabs(a[i+1].y-a[i].y))&1)) {bo=1; break;}
	if (bo)
	{
		if (ga==1) limpl--; else if (limpl<limpr) limpl++; else return puts("NO"),0;
		if (ga==2) limml--; else if (limml<limmr) limml++; else return puts("NO"),0;
		for (int i=1; i<=n+1; i++) a[i].x+=a[i].k*X,a[i].y+=a[i].k*Y;
		X=(limpl+limml)/2; Y=(limpl-limml)/2;
		for (int i=1; i<=n+1; i++) a[i].x-=a[i].k*X,a[i].y-=a[i].k*Y;
	}
	for (int i=0; i<=n; i++)
		if (((a[i+1].b-a[i].b)&1)!=((getabs(a[i+1].x-a[i].x)+getabs(a[i+1].y-a[i].y))&1)) return puts("NO"),0;
	for (int i=0; i<=n; i++)
	{
		for (int j=a[i].x; j<a[i+1].x; j++) a[i].x++,putchar('R'),a[i].b++;
		for (int j=a[i].x; j>a[i+1].x; j--) a[i].x--,putchar('L'),a[i].b++;
		for (int j=a[i].y; j<a[i+1].y; j++) a[i].y++,putchar('U'),a[i].b++;
		for (int j=a[i].y; j>a[i+1].y; j--) a[i].y--,putchar('D'),a[i].b++;
		for (int j=a[i].b; j<a[i+1].b; j+=2) putchar('U'),putchar('D');
	}
	return puts(""),0;
}