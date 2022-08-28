#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
};
int n,m,pre[1000005][2],tans[1000005];
set<pt> st1,st2;
int main()
{
	scanf("%d%d",&n,&m);
	st1.insert(pt());
	st2.insert(pt());
	for(int i=1;i<=n;i++)
	{
		int x,l1,r1,l2,r2,fl1=0,fl2=0;
		scanf("%d%d%d%d%d",&x,&l1,&r1,&l2,&r2);
		if(l1<=x&&x<=r1)
		{
			set<pt>::iterator it=st2.lower_bound(pt(l2,0));
			if(it!=st2.end()&&it->val<=r2)
			{
				fl1=1;
				while(!st2.empty()&&st2.begin()->val<l2) st2.erase(st2.begin());
				while(!st2.empty()&&(--st2.end())->val>r2) st2.erase(--st2.end());
				pre[i][0]=it->id;
			}
		}
		if(l2<=x&&x<=r2)
		{
			set<pt>::iterator it=st1.lower_bound(pt(l1,0));
			if(it!=st1.end()&&it->val<=r1)
			{
				fl2=1;
				while(!st1.empty()&&st1.begin()->val<l1) st1.erase(st1.begin());
				while(!st1.empty()&&(--st1.end())->val>r1) st1.erase(--st1.end());
				pre[i][1]=it->id;
			}
		}
		if(!fl1) st2.clear();
		if(!fl2) st1.clear();
		if(fl1) st1.insert(pt(x,i));
		if(fl2) st2.insert(pt(x,i));
		/*printf("i=%d,st1=",i);
		for(set<pt>::iterator j=st1.begin();j!=st1.end();j++)
			printf("(%d,%d) ",j->val,j->id);
		printf(",st2=");
		for(set<pt>::iterator j=st2.begin();j!=st2.end();j++)
			printf("(%d,%d) ",j->val,j->id);
		printf("\n");*/
		if(!fl1&&!fl2)
		{
			printf("No\n");
			return 0;
		}
	}
	memset(tans,0xff,sizeof(tans));
	int u=st2.begin()->id,fl=1;
	tans[n]=0;
	while(u)
	{
		tans[u]=fl;
		u=pre[u][fl];
		fl^=1;
	}
	for(int i=n-1;i>0;i--)
		if(tans[i]==-1) tans[i]=tans[i+1];
	printf("Yes\n");
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}