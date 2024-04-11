#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
#include<cmath>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

struct node{
	int v,id;
}a[N*2+1];

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int n,x1,x2,c[N],ne[N];

ll w[N];

inline int calc(int x,int y)
{
	return x/y+((x%y)!=0);
} 

bool solve(int p,int q,bool f)
{
	for(int i=1;i<=n;i++)
	{
		int h=ceil((double)p/a[i].v);
		int l=i+h;
		if(l>n)
			continue;
		if(w[ne[l]]<q)
			continue;
		int pos=ne[l];
		int k=ceil((double)q/a[pos].v);
		puts("Yes");
		if(f)
		{
			swap(h,k);
			swap(i,pos);
		}
		printf("%d %d\n",h,k);
		for(int j=i;j<i+h;j++)
			printf("%d ",a[j].id);
		puts("");
		for(int j=pos;j<pos+k;j++)
			printf("%d ",a[j].id);
		puts("");
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&x1,&x2);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		a[i].v=c[i],a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		w[i]=1ll*a[i].v*(n-i+1);
	ne[n]=n;
	for(int i=n-1;i>=1;i--)
		if(w[i]>w[ne[i+1]])
			ne[i]=i;
		else
			ne[i]=ne[i+1];
	if(solve(x1,x2,0))
		return 0;
	if(solve(x2,x1,1))
		return 0;
	puts("No");
}