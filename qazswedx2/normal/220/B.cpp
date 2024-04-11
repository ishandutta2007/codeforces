#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct qt
{
	int l,r,id;
	bool operator<(const qt q) const
	{
		return r<q.r;
	}
}q[1000005];
int n,m,a[1000005],sum[1000005],qans[1000005];
vector<int> val[1000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	//printf("modify:x=%d,v=%d\n",x,v);
	for(int i=x;i<=n;i+=lowbit(i))
		sum[i]+=v;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=sum[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>n) a[i]=n+1;
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		val[a[i]].push_back(i);
		int sz=val[a[i]].size(),id=sz-a[i],id2=sz-a[i]-1,id3=sz-a[i]-2;
	//	printf("i=%d,sz=%d,id=%d,id2=%d\n",i,sz,id,id2);
		if(id>=0) modify(val[a[i]][id],1);
		if(id2>=0) modify(val[a[i]][id2],-2);
		if(id3>=0) modify(val[a[i]][id3],1);
		while(nw<=m&&q[nw].r==i)
		{
			qans[q[nw].id]=query(i)-query(q[nw].l-1);
			nw++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",qans[i]);
	return 0;
}