#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int s,a;
}a[1000005],c[1000005],d[1000005];
int n,b[2000005],bt,at,ct,sum[2000005],dt;
bool cmp1(pt x,pt y)
{
	return x.s<y.s;
}
bool cmp2(pt x,pt y)
{
	return x.a<y.a;
}
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	for(int i=x;i;i-=lowbit(i))
		sum[i]+=v;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i<=bt;i+=lowbit(i))
		ans+=sum[i];
	return ans;
}
void F(int &x)
{
	x=lower_bound(b+1,b+bt+1,x)-b;
}
int main()
{
	int las;
	scanf("%d%d",&n,&las);
	b[++bt]=las;
	for(int i=1;i<=n;i++)
	{
		pt p;
		scanf("%d%d",&p.s,&p.a);
		b[++bt]=p.s;
		b[++bt]=p.a;
		if(p.a<=p.s) a[++at]=p;
		else c[++ct]=p;
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	F(las);
	for(int i=1;i<=at;i++)
		F(a[i].a),F(a[i].s);
	for(int i=1;i<=ct;i++)
		F(c[i].a),F(c[i].s);
	sort(a+1,a+at+1,cmp1);
	sort(c+1,c+ct+1,cmp2);
	int nw=1,ans=0;
	for(int i=1;i<=at;i++)
		if(a[i].s>=las) ans++;
	for(int i=1;i<=ct;i++)
	{
		while(nw<=at&&a[nw].s<c[i].a)
		{
			modify(a[nw].a,1);
			nw++;
		}
		int q=query(c[i].s+1);
		if(!q)
		{
			if(c[i].s>=las)
			{
				ans++;
				las=c[i].a;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}