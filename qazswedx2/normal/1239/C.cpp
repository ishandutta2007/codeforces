#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int n,k,a[100005],sum[100005],q[100005],head=1,tail;
int b[100005];
ll tans[100005],qt; 
set<int> st;
bool cmp(const int x,const int y)
{
	return a[x]!=a[y]?a[x]<a[y]:x<y;
}
int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
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
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=i;
	sort(b+1,b+n+1,cmp);
	int bt=1;
	while(bt<=n)
	{
		//printf("i=%d\n",b[bt]);
		int nt=a[b[bt]];
		while(head<=tail&&qt<nt)
		{
			//printf("head=%d,tail=%d\n",head,tail);
			int u=q[head];
			head++;
			modify(u,-1);
			tans[u]=qt;
			//printf("del:%d,%d\n",u,qt);
			if(st.size())
			{
				int v=*st.begin();
				if(query(v)==0)
				{
					q[++tail]=v;
					modify(v,1);
					st.erase(v);
					//printf("ins2:%d\n",v);
				}
			}
			qt+=k;
		}
		st.insert(b[bt]);
		if(query(b[bt])==0)
		{
			st.erase(b[bt]);
			q[++tail]=b[bt];
			modify(b[bt],1);
			if(head==tail) qt=nt+k;
			//printf("ins:%d\n",b[bt]);
		}
		bt++;
	}
	while(head<=tail)
	{
		int u=q[head];
		head++;
		modify(u,-1);
		tans[u]=qt;
		//printf("del:%d\n",u);
		if(st.size())
		{
			int v=*st.begin();
			if(query(v)==0)
			{
				q[++tail]=v;
				modify(v,1);
				st.erase(v);
			}
		}
		qt+=k;
	}
	for(int i=1;i<=n;i++)
		printf("%I64d ",tans[i]);
	return 0;
}