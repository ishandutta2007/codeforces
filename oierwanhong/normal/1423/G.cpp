#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
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
const int MAXN = 200011;
ll c[MAXN],d[MAXN];
ll res[MAXN];
int a[MAXN];
int last[MAXN],pre[MAXN];
int n,m;
struct Segment_Tree_Sum
{
	struct node
	{
		ll sum,tag;
	}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void pushdown(un l,un r,un num)
	{
		if(!rt.tag)return;
		un mid=(l+r)>>1;
		tl.sum+=rt.tag*(mid-l+1),tl.tag+=rt.tag;
		tr.sum+=rt.tag*(r-mid),tr.tag+=rt.tag;
		rt.tag=0;
	}
	void Add(un ql,un qr,ll k,un l=1,un r=n,un num=1)
	{
		umin(qr,unsigned(n));
		if(ql<=l&&r<=qr)
		{
			rt.sum+=k*(r-l+1),rt.tag+=k;
			return;
		}
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		if(ql<=mid)Add(ql,qr,k,l,mid,num<<1);
		if(qr>mid)Add(ql,qr,k,mid+1,r,num<<1|1);
		rt.sum=tl.sum+tr.sum;
	}
	ll Qsum(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.sum;
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		ll res=0;
		if(ql<=mid)res+=Qsum(ql,qr,l,mid,num<<1);
		if(qr>mid)res+=Qsum(ql,qr,mid+1,r,num<<1|1);
		return res;
	}
}T;
int st,ed,val;
struct one
{
	int l,r,val;
	one(){}
	one(int l,int r,int val):l(l),r(r),val(val) {}
};
std::vector<one>Q;
struct Segment_Tree_Interval
{
	struct node
	{
		int maxv,minv,tag;
	}t[MAXN<<2|1];
	void pushdown(un num)
	{
		if(rt.tag==-1)return;
		tl.maxv=tl.minv=tl.tag=rt.tag;
		tr.maxv=tr.minv=tr.tag=rt.tag;
		rt.tag=-1;
	}
	void pushup(un num){rt.maxv=max(tl.maxv,tr.maxv),rt.minv=min(tl.minv,tr.minv);}
	void init(un l=1,un r=n,un num=1)
	{
		rt.tag=-1;
		if(l==r)rt.maxv=rt.minv=a[l];
		else
		{
			un mid=(l+r)>>1;
			init(l,mid,num<<1),init(mid+1,r,num<<1|1);
			pushup(num);
		}
	}
	void Cover(un ql,un qr,int k,un l=1,un r=n,un num=1)
	{
		//printf("cover [%u,%u,%d]\n",l,r,k);
		if(ql<=l&&r<=qr&&rt.minv==rt.maxv)
		{
			//printf("new [%d,%d,%d]\n",l,r,rt.maxv);
			if(val==rt.maxv)ed=r;
			else
			{
				if(st)Q.emplace_back(one(st,ed,val));
				st=l,ed=r,val=rt.maxv;
			}
			rt.minv=rt.maxv=rt.tag=k;
			return;
		}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)Cover(ql,qr,k,l,mid,num<<1);
		if(qr>mid)Cover(ql,qr,k,mid+1,r,num<<1|1);
		pushup(num);
	}
	int Query(un pos,un l=1,un r=n,un num=1)
	{
		if(l==r)return rt.maxv;
		pushdown(num);
		un mid=(l+r)>>1;
		if(pos<=mid)return Query(pos,l,mid,num<<1);
		else return Query(pos,mid+1,r,num<<1|1);
	}
}I;
std::set<pii>S[100005];
int Get_pre(int i,int v)
{
	return min((--S[v].lower_bound(pii(i-1,MAXN)))->second,i-1);
}
void Add_interval(int l,int r,int v,int k)
{
	int p=Get_pre(l,v);
	T.Add(1,l-p,1*k);
	if(l>1)T.Add(n-l+2,n-p+1,-1*k);
	if(l<r)T.Add(1,1,(r-l)*k),T.Add(n-r+2,n-l+1,-1*k);
}
bool vis[MAXN];
int main()
{
	n=read(),m=read();
	//for(int k=1;k<=n;++k)res[k]-=(1+(n-k+1))*(n-k+1)/2+(k-1)*(n-k+1);
	for(int i=1;i<=100000;++i)S[i].insert(pii(0,0)),S[i].insert(pii(n+1,n+1));
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		pre[i]=last[a[i]];
		//[i-pre,n-pre]
		//[1,n-i+1]
		T.Add(1,i-pre[i],1);
		if(i>1)T.Add(n-i+2,n-pre[i]+1,-1);
		/*
		for(int j=pre[i]+1;j<=i;++j)
		{
			//[i-j+1,n-j+1]
			for(int k=i-j+1;k<=n-j+1;++k)++res[k];
		}
		*/
		last[a[i]]=i,S[a[i]].insert(pii(i,i));
	}
	I.init();
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			std::vector<int>colors;
			int ql=read(),qr=read(),k=read();
			st=ed=val=0;
			Q.clear();
			I.Cover(ql,qr,k);
			Q.emplace_back(one(st,ed,val));
			for(auto X:Q)
			{
				Add_interval(X.l,X.r,X.val,-1);
				if(!vis[X.val])colors.emplace_back(X.val),vis[X.val]=1;
			}
			if(!vis[k])colors.emplace_back(k),vis[k]=1;
			for(auto c:colors)
			{
				vis[c]=0;
				auto it=--S[c].lower_bound(pii(qr+1,0));
				if(it->second<=qr)++it;
				int p=max(it->first,qr+1);
				if(p<=n)Add_interval(p,p,c,-1);
			}
			for(auto X:Q)
			{
				int l=X.l,r=X.r;
				int v=X.val;
				auto it=--S[v].lower_bound(pii(l+1,0));
				std::vector<pii>nxt;
				while(it->first<=r)
				{
					if(it->first<l)nxt.emplace_back(pii(it->first,min(it->second,l-1)));
					if(it->second>r)nxt.emplace_back(pii(r+1,it->second));
					S[v].erase(it++);
				}
				for(auto R:nxt)S[v].insert(R);
			}
			S[k].insert(pii(ql,qr));
			Add_interval(ql,qr,k,1);
			for(auto c:colors)
			{
				vis[c]=0;
				auto it=--S[c].lower_bound(pii(qr+1,0));
				if(it->second<=qr)++it;
				int p=max(it->first,qr+1);
				if(p<=n)Add_interval(p,p,c,1);
			}
		}
		else printf("%lld\n",T.Qsum(1,read()));
	}
	return 0;
}