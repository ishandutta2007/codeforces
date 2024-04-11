#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
struct pt
{
	int val,val2,id;
	pt(int val=0,int val2=0,int id=0):val(val),val2(val2),id(id){}
	bool operator<(const pt x) const
	{
		if(val!=x.val) return val>x.val;
		return val2>x.val2;
	}
};
int q,vis[1000005],t;
priority_queue<pt> pq,pq2;
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int op,x;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			t++;
			pq.push(pt(i,0,t));
			pq2.push(pt(-x,i,t));
		}
		if(op==2)
		{
			while(vis[pq.top().id]) pq.pop();
			int u=pq.top().id;
			pq.pop();
			printf("%d ",u);
			vis[u]=1;
		}
		if(op==3)
		{
			while(vis[pq2.top().id]) pq2.pop();
			int u=pq2.top().id;
			pq2.pop();
			printf("%d ",u);
			vis[u]=1;
		}
	}
	return 0;
}