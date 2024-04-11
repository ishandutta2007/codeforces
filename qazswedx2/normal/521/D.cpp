#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct qn
{
	int id,fl;
	ll a,b;
}q[100005];
struct pt
{
	int id,val,fl;
	pt(int id=0,int val=0,int fl=0):id(id),val(val),fl(fl){}
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
};
int n,m,k,a[100005],mx[100005],mxid[100005],qt;
vector<pt> b[100005];
bool operator<(const qn x,const qn y)
{
	return (long double)x.a*y.b>(long double)y.a*x.b;
}
bool cmp(const qn x,const qn y)
{
	return x.fl<y.fl;
}
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int op,id,x;
		scanf("%d%d%d",&op,&id,&x);
		if(op==1) 
		{
			if(mx[id]<x)
			{
				mx[id]=x;
				mxid[id]=i;
			}
		}
		if(op==2) b[id].push_back(pt(i,x,2));
		if(op==3)
		{
			qt++;
			q[qt].id=i;
			q[qt].a=x,q[qt].b=1;
			q[qt].fl=3;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(a[i]<mx[i])
			b[i].push_back(pt(mxid[i],mx[i]-a[i],1));
		int sz=b[i].size();
		sort(b[i].begin(),b[i].end());
		ll nw=a[i];
		for(int j=0;j<sz;j++)
		{
			pt u=b[i][j];
			qt++;
			q[qt].id=u.id;
			q[qt].fl=u.fl;
			q[qt].a=nw+u.val;
			q[qt].b=nw;
			nw+=u.val;
		}
	}
	sort(q+1,q+qt+1);
	/*for(int i=1;i<=qt;i++)
	{
		printf("i=%d,id=%d,fl=%d,%lld/%lld\n",i,q[i].id,q[i].fl,q[i].a,q[i].b);
	}*/
	m=min(m,qt);
	sort(q+1,q+m+1,cmp);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d ",q[i].id);
	return 0;
}