#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 200011;
struct node
{
	int ls,rs,maxv;
}t[MAXN<<5|1];
#define rt t[num]
int root[MAXN],cnt=0;
void modify(int& num,int pos,int val,un l=0,un r=100000)
{
	if(!num)num=++cnt;
	umax(rt.maxv,val);
	if(l==r)return;
	un mid=(l+r)>>1;
	if(pos<=mid)modify(rt.ls,pos,val,l,mid);
	else modify(rt.rs,pos,val,mid+1,r);
}
int Qmax(int num,int ql,int qr,un l=0,un r=100000)
{
	if(!num||ql>qr)return 0;
	if(ql<=l&&r<=qr)return rt.maxv;
	un mid=(l+r)>>1;
	int res=0;
	if(ql<=mid)umax(res,Qmax(rt.ls,ql,qr,l,mid));
	if(qr>mid)umax(res,Qmax(rt.rs,ql,qr,mid+1,r));
	return res;
}
int main()
{
	int n=read(),m=read();
	while(m--)
	{
		int u=read(),v=read(),w=read();
		modify(root[v],w,Qmax(root[u],0,w-1)+1);
	}
	int ans=0;
	for(int u=1;u<=n;++u)umax(ans,Qmax(root[u],0,100000));
	printf("%d\n",ans);
	return 0;
}