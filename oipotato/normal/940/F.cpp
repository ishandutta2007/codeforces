#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
const int magic=2000;
struct Query
{
	int ti,l,r,LB,RB;
}p1[100010];
struct Modify
{
	int ti,p,x;
}p2[100010];
bool cmp(const Query &a,const Query &b)
{
	if(a.LB!=b.LB)
	{
		return a.LB<b.LB;
	}
	else if(a.RB!=b.RB)
	{
		return a.RB<b.RB;
	}
	else return a.ti<b.ti;
}
int num[100010],times[200010],a[100010],tmpa[100010],ans[100010],nxt[100010],n,q,num1,num2,tot,b[200010];
int getans()
{
	for(int i=1;;i++)
	{
		if(!num[i])
		{
			return i;
		}
	}
}
inline void addans(int x)
{
	num[x]++;
}
inline void delans(int x)
{
	num[x]--;
}
void add(int x)
{
	delans(times[x]);
	times[x]++;
	addans(times[x]);
}
void del(int x)
{
	delans(times[x]);
	times[x]--;
	addans(times[x]);
}
void time_move(int st,int x)
{
	//printf("%d %d %d\n",st,x,p2[st].ti);
	for(int i=st;i<=num2&&p2[i].ti<=p1[x].ti;i++)
	{
		if(p1[x-1].l<=p2[i].p&&p2[i].p<=p1[x-1].r)
		{
			del(tmpa[p2[i].p]);
			add(p2[i].x);
		}
		tmpa[p2[i].p]=p2[i].x;
	}
}
void init(int x)
{
	memset(num,0,sizeof(num));
	memset(times,0,sizeof(times));
	for(int i=1;i<=n;i++)
	{
		tmpa[i]=a[i];
	}
	for(int i=1;i<=num2&&p2[i].ti<=p1[x].ti;i++)
	{
		tmpa[p2[i].p]=p2[i].x;
	}
	for(int i=p1[x].l;i<=p1[x].r;i++)
	{
		add(tmpa[i]);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[++tot]=a[i];
	}
	for(int i=1;i<=q;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			++num1;
			scanf("%d%d",&p1[num1].l,&p1[num1].r);
			p1[num1].ti=i;
			p1[num1].LB=p1[num1].l/magic;
			p1[num1].RB=p1[num1].r/magic;
		}
		else
		{
			++num2;
			scanf("%d%d",&p2[num2].p,&p2[num2].x);
			p2[num2].ti=i;
			for(int j=i;j&&!nxt[j];j--)
			{
				nxt[j]=num2;
			}
			b[++tot]=p2[num2].x;
		}
	}
	sort(b+1,b+tot+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	}
	for(int i=1;i<=num2;i++)
	{
		p2[i].x=lower_bound(b+1,b+tot+1,p2[i].x)-b;
	}
	sort(p1+1,p1+num1+1,cmp);
	for(int i=1;i<=num1;i++)
	{
		if(i==1||p1[i].LB!=p1[i-1].LB||p1[i].RB!=p1[i-1].RB)
		{
			init(i);
		}
		else
		{
			time_move(nxt[p1[i-1].ti],i);
			for(int j=p1[i-1].l;j<p1[i].l;j++)
			{
				del(tmpa[j]);
			}
			for(int j=p1[i].l;j<p1[i-1].l;j++)
			{
				add(tmpa[j]);
			}
			for(int j=p1[i-1].r+1;j<=p1[i].r;j++)
			{
				add(tmpa[j]);
			}
			for(int j=p1[i].r+1;j<=p1[i-1].r;j++)
			{
				del(tmpa[j]);
			}
		}
		ans[p1[i].ti]=getans();
		/*for(int j=1;j<=5;j++)
		{
			printf("%d ",num[j]);
		}
		printf("%d\n",ans[p1[i].ti]);*/
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i])
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}