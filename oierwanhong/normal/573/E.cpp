#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef std::string str;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
using std::max;
using std::min;
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());
//std::mt19937 rd(233);
struct FHQ_Treap
{
	struct node
	{
		int ls,rs,size,data;
		ll f,sum,tag;
		node(){ls=rs=size=data=f=sum=tag=0;}
	}t[MAXN];
	int tot,root;
	FHQ_Treap(){tot=root=0;}
	int newnode()
	{
		++tot;
		t[tot].size=1,t[tot].data=rd();
		return tot;
	}
#define rt t[cur]
#define tl t[rt.ls]
#define tr t[rt.rs]
	//void split(int cur,int k,int& x,int& y)
	//{
	//	if(!cur){x=y=0;return;}
	//}
	void pushtag(int cur,ll k){if(cur)rt.f+=k,rt.sum+=rt.size*k,rt.tag+=k;}
	void pushdown(int cur){pushtag(rt.ls,rt.tag),pushtag(rt.rs,rt.tag),rt.tag=0;}
	void pushup(int cur){rt.size=tl.size+tr.size+1,rt.sum=tl.sum+rt.f+tr.sum;}
	void split(int cur,int pres,ll k,int& x,int& y)
	{
		if(!cur){x=y=0;return;}
		//printf("Split %d,k=%lld,ls=%d,rs=%d,Rtf=%lld\n",cur,k,rt.ls,rt.rs,rt.f);
		pushdown(cur);
		if((pres+tl.size+1)*k>rt.f)
			y=cur,split(rt.ls,pres,k,x,rt.ls);
		else x=cur,split(rt.rs,pres+tl.size+1,k,rt.rs,y);
		pushup(cur);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x|y;
		//printf("Merge(%d,%d)\n",x,y);
		if(t[x].data<=t[y].data)
		{
			pushdown(y);
			t[y].ls=merge(x,t[y].ls);
			return pushup(y),y;
		}
		else
		{
			pushdown(x);
			t[x].rs=merge(t[x].rs,y);
			return pushup(x),x;
		}
	}
	void update(ll k)
	{
		int x,y;
		split(root,0,k,x,y);
		//printf("L=%d,R=%d\n",t[x].size,t[y].size);
		int p=newnode();
		//printf("P=%d,F[p]=%lld\n",p,(t[x].size+1)*k);
		t[p].sum=t[p].f=(t[x].size+1)*k,pushtag(y,k);
		root=merge(x,merge(p,y));
		//printf("All=%d\n",t[root].size);
	}
	ll Query(int cur,ll pres)
	{
		pushdown(cur);
		ll res=pres+tl.sum+rt.f;
		//printf("F[%d]=%lld+%lld+%lld=%lld\n",cur,pres,tl.sum,rt.f, res);
		if(rt.ls)umax(res,Query(rt.ls,pres));
		if(rt.rs)umax(res,Query(rt.rs,pres+tl.sum+rt.f));
		return res;
	}
	ll Query(){return Query(root,0);}
}t;
int main()
{
	int n=read();
	while(n--)t.update(read());
	printf("%lld\n",max(0ll,t.Query()));
	return 0;
}