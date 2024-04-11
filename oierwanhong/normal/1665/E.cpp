#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011,LG = 30;
struct node
{
	int ls,rs,sum;
}t[MAXN<<6|1];
int root[MAXN],cnt;
#define rt t[num]
#define tl t[rt.ls]
#define tr t[rt.rs]
int cpynode(int x)
{
	int num=++cnt;
	rt.ls=t[x].ls,rt.rs=t[x].rs,rt.sum=t[x].sum;
	return num;
}
void insert(int& num,int x,int k)
{
	num=cpynode(num),++rt.sum;
	//printf("num=%d,x=%d,k=%d,sum=%d\n",num,x,k,rt.sum);
	if(k<0)return;
	if(x&(1<<k))insert(rt.rs,x,k-1);
	else insert(rt.ls,x,k-1);
}
void debug(int num,int k)
{
	printf("num=%d,sum=%d\n",num,rt.sum);
	if(k<0)return;
	if(rt.ls)debug(rt.ls,k-1);
	if(rt.rs)debug(rt.rs,k-1);
}
std::vector<int>extra;
void get(int pre,int num,int high,int k)
{
	//printf("Get: pre=%d,num=%d,high=%d,k=%d,sum=%d\n",pre,num,high,k,rt.sum-t[pre].sum);
	if(k<0)
	{
		//printf("pb %d\n",high);
		extra.emplace_back(high);return;
	}
	int d=tl.sum-t[t[pre].ls].sum;
	if(d)get(t[pre].ls,rt.ls,high,k-1);
	else get(t[pre].rs,rt.rs,high|(1<<k),k-1);
}
void Query(int pre,int num,int high,int k)
{
	if(k<0)
	{
		//printf("Bottom at %d %d %d %d\n",pre,num,high,k);
		int d=rt.sum-t[pre].sum;
		for(int x=1;x<=d&&x<=2;++x)extra.emplace_back(high);
		return;
	}
	int d=tl.sum-t[t[pre].ls].sum;
	//printf("pre=%d,num=%d,[d=%d],high=%d,k=%d\n",pre,num,d,high,k);
	if(d>1)Query(t[pre].ls,rt.ls,high,k-1);
	else
	{
		if(d==1)get(t[pre].ls,rt.ls,high,k-1);
		Query(t[pre].rs,rt.rs,high|(1<<k),k-1);
	}
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)
		{
			root[i]=root[i-1];
			insert(root[i],read(),LG);
			//debug(root[i],LG);
		}
		int q=read();
		while(q--)
		{
			int l=read(),r=read();
			extra.clear();
			Query(root[l-1],root[r],0,LG);
			int res=1<<30;
			for(int i=0;i<int(extra.size());++i)
				for(int j=i+1;j<int(extra.size());++j)
					umin(res,extra[i]|extra[j]);
			printf("%d\n",res);
		}
	}
	return 0;
}