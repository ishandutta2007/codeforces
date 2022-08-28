#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct tpt
{
	int val,id;
	tpt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const tpt x) const
	{
		return val==x.val?x.id<id:val>x.val;
	}
};
struct pt
{
	int l,r,id;
}b[300005];
int n,m,a[300005],tans[300005],t;
set<tpt> st;
bool cmp(const pt x,const pt y)
{
	return x.l==y.l?x.r<y.r:x.l<y.l;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&b[i].l,&b[i].r),b[i].id=i;
	sort(b+1,b+n+1,cmp);
	int tnw=1;
	for(int i=1;i<=200000;i++)
	{
		while(b[tnw].l==i)
		{
			while(st.size()&&(--st.end())->val<i)
			{
				//printf("%d\n",(--st.end())->val);
				st.erase(--st.end());
			}
			st.insert(tpt(b[tnw].r,b[tnw].id));
			//printf("tnw=%d,l=%d,r=%d,st=%d\n",tnw,b[tnw].l,b[tnw].r,st.size());
			if(st.size()>m)
			{
				//printf("--");
		 		tans[++t]=st.begin()->id;
				st.erase(st.begin());
			}
			tnw++;
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d ",tans[i]);
	return 0;
}