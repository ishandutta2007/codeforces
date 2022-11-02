#include<cstdio>
using namespace std;
int a[30],b[30],go[2700010][2],num[2700010],x,y,q,tot,opt;
void Dec_to_Bin(int x,int a[])
{
	for(int i=27;i;i--)
	{
		a[i]=x&1;
		x>>=1;
	}
}
void ins(int a[])
{
	int p=0;
	for(int i=1;i<=27;i++)
	{
		if(!go[p][a[i]])go[p][a[i]]=++tot;
		p=go[p][a[i]];
		num[p]++;
	}
}
void del(int a[])
{
	int p=0;
	for(int i=1;i<=27;i++)
	{
		p=go[p][a[i]];
		num[p]--;
	}
}
int query(int a[],int b[])
{
	int tans=0,p=0;
	for(int i=1;i<=27;i++)
	{
		if(b[i])tans+=num[go[p][a[i]]];
		if(!go[p][a[i]^b[i]])break;
		p=go[p][a[i]^b[i]];
	}
	return tans;
}
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&x);
			Dec_to_Bin(x,a);
			ins(a);
		}
		else if(opt==2)
		{
			scanf("%d",&x);
			Dec_to_Bin(x,a);
			del(a);
		}
		else
		{
			scanf("%d%d",&x,&y);
			Dec_to_Bin(x,a);
			Dec_to_Bin(y,b);
			printf("%d\n",query(a,b));
		}
	}
	return 0;
}