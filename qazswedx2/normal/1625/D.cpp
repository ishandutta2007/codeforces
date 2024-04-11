#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m=30,k,a[1000005],c[1000005],rc[1000005],ch[10000005][2],ct=1;
int tans[1000005],t;
void ins(int x)
{
	int p=1;
	for(int i=m-1;i>=0;i--)
	{
		int c=(x>>i)&1;
		if(!ch[p][c])
		{
			ch[p][c]=++ct;
			ch[ct][0]=ch[ct][1]=0;
		}
		p=ch[p][c];
	}
}
int query(int x)
{
	int p=1,ans=0;
	for(int i=m-1;i>=0;i--)
	{
		int c=(x>>i)&1;
		if(ch[p][c^1]) p=ch[p][c^1],ans|=(1<<i);
		else p=ch[p][c];
	}
	if(!p) return -1;
	return ans;
}
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[i]=i;
	if(!k)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		printf("\n");
		return 0;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		rc[c[i]]=i;
	sort(a+1,a+n+1);
	int lim=1;
	while(lim<=k) lim<<=1;
	sort(a+1,a+n+1);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&(a[r+1]^a[l])<lim) r++;
		ct=1;
		ch[1][0]=ch[1][1]=0;
		for(int i=l;i<=r;i++)
			ins(a[i]);
		int fl=0;
		for(int i=l;i<=r;i++)
		{
			int q=query(a[i]);
			if(q>=k)
			{
				tans[++t]=i;
				tans[++t]=lower_bound(a+1,a+n+1,a[i]^q)-a;
				fl=1;
				break;
			}
		}
		if(!fl) tans[++t]=l;
	}
	if(t==1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d ",c[tans[i]]);
	printf("\n");
	return 0;
}