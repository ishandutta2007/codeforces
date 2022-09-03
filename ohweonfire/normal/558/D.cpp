#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005;
int h,q,ord[maxn];
LL ql[maxn],qr[maxn];
bool cmp(int x,int y)
{
	if(ql[x]!=ql[y])return ql[x]<ql[y];
	return qr[x]<qr[y];
}
int main()
{
	scanf("%d%d",&h,&q);
	int i,a,cnt=0;
	LL L=1ll<<(h-1),R=(1ll<<h)-1,l,r;
	if(q==0)
	{
		if(h==1)puts("1");
		else puts("Data not sufficient!");
		return 0;
	}
	while(q--)
	{
		scanf("%d%I64d%I64d%d",&i,&l,&r,&a);
		l*=(1ll<<(h-i));
		r++;
		r*=(1ll<<(h-i));
		r--;
		if(a==1)
		{
			ql[++cnt]=L;
			qr[cnt]=l-1;
			ql[++cnt]=r+1;
			qr[cnt]=R;
		}
		else
		{
			ql[++cnt]=l;
			qr[cnt]=r;
		}
	}
	for(int i=1;i<=cnt;i++)ord[i]=i;
	sort(ord+1,ord+cnt+1,cmp);
	LL ans=-1,curr;
	if(ql[ord[1]]>L)
	{
		if(ql[ord[1]]==L+1)ans=L;
		else
		{
			puts("Data not sufficient!");
			return 0;
		}
	}
	for(int _=1;_<=cnt;_++)
	{
		curr=qr[ord[_]];
		while(_!=cnt&&curr>=ql[ord[_+1]]-1)
			curr=max(curr,qr[ord[++_]]*1ll);
		if(_==cnt&&curr<R)
		{
			if((ans!=-1&&ans!=R)||curr<R-1)
			{
				puts("Data not sufficient!");
				return 0;
			}
			ans=R;
		}
		if(_!=cnt)
		{
			if((ans!=-1&&ans!=curr+1)||curr!=ql[ord[_+1]]-2)
			{
				puts("Data not sufficient!");
				return 0;
			}
			ans=curr+1;
		}
	}
	if(ans==-1)
	{
		puts("Game cheated!");
		return 0;
	}
	printf("%I64d\n",ans);
	return 0;
}