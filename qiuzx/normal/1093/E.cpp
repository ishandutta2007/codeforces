#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define F first
#define S second
#define N 200010
#define SQ 203
#define SZ 1000
using namespace std;
int rint(){
	int ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
int n,m,a[N],b[N],c[N],pre[N],bit[SQ][N];
int lowbit(int x)
{
	return x&(-x);
}
void add(int Qnum,int id)
{
	while(id<N)
	{
		bit[Qnum][id]++;
		id+=lowbit(id);
	}
	return;
}
void erase(int Qnum,int id)
{
	while(id<N)
	{
		bit[Qnum][id]--;
		id+=lowbit(id);
	}
}
int query(int Qnum,int id)
{
	int ret=0;
	while(id>0)
	{
		ret+=bit[Qnum][id];
		id-=lowbit(id);
	}
	return ret;
}
int main(){
	int i,j,tp,la,lb,ra,rb,x,y,ans;
	n=rint();
	m=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint()-1;
	}
	for(i=0;i<n;i++)
	{
		b[i]=rint()-1;
	}
	for(i=0;i<n;i++)
	{
		pre[a[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		c[i]=pre[b[i]];
	}
	for(i=0;i<n;i++)
	{
		add(i/SZ,c[i]+2);
	}
	for(i=0;i<m;i++)
	{
		tp=rint();
		if(tp==1)
		{
			la=rint();
			ra=rint();
			lb=rint()-1;
			rb=rint()-1;
			ans=0;
			if(lb/SZ==rb/SZ)
			{
				for(j=lb;j<=rb;j++)
				{
					if(la-1<=c[j]&&c[j]<ra)
					{
						ans++;
					}
				}
			}
			else
			{
				for(j=lb;j/SZ==lb/SZ;j++)
				{
					if(la-1<=c[j]&&c[j]<ra)
					{
						ans++; 
					}
				}
				for(j=rb;j/SZ==rb/SZ;j--)
				{
					if(la-1<=c[j]&&c[j]<ra)
					{
						ans++;
					}
				}
				for(j=lb/SZ+1;j<rb/SZ;j++)
				{
					ans+=query(j,ra+1)-query(j,la);
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			x=rint()-1;
			y=rint()-1;
			erase(x/SZ,c[x]+2);
			erase(y/SZ,c[y]+2);
			add(x/SZ,c[y]+2);
			add(y/SZ,c[x]+2);
			swap(c[x],c[y]);
		}
	}
	return 0;
}