#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+500;
int n,m;
pair<int,int>w[N];
int ans[N];
struct Node
{
	int mi,mx;
	Node(){}
	Node(const int &x){mi=mx=x;}
	Node(const int &_mi,const int &_mx){mi=_mi,mx=_mx;}
};
Node operator +(const Node &a,const Node &b){return Node(min(a.mi,b.mi),max(a.mx,b.mx));}
struct SEG
{
	Node a[N<<2];
	int tag[N<<2];
	void build(int rot,int lt,int rt)
	{
		if(lt==rt){a[rot]=lt;return;}
		int mid=(lt+rt)>>1;
		build(rot<<1,lt,mid),build(rot<<1|1,mid+1,rt);
		a[rot]=a[rot<<1]+a[rot<<1|1];
	}
	void upd(int rot,int w){a[rot].mi+=w,a[rot].mx+=w;tag[rot]+=w;}
	void pushdown(int rot)
	{
		if(tag[rot])
		{
			int t=tag[rot];tag[rot]=0;
			upd(rot<<1,t),upd(rot<<1|1,t);
		}
	}
	
	void update(int rot,int lt,int rt,int lq,int rq,int w)
	{
		if(lt>=lq&&rt<=rq){upd(rot,w);return;}
		int mid=(lt+rt)>>1;pushdown(rot);
		if(lq<=mid)update(rot<<1,lt,mid,lq,rq,w);
		if(rq>mid)update(rot<<1|1,mid+1,rt,lq,rq,w);
		a[rot]=a[rot<<1]+a[rot<<1|1];
	}
	Node query(int rot,int lt,int rt,int lq,int rq)
	{
		if(lt>=lq&&rt<=rq)return a[rot];
		pushdown(rot);int mid=(lt+rt)>>1;
		if(rq<=mid)return query(rot<<1,lt,mid,lq,rq);
		if(lq>mid)return query(rot<<1|1,mid+1,rt,lq,rq);
		return query(rot<<1,lt,mid,lq,rq)+query(rot<<1|1,mid+1,rt,lq,rq);
	}
	Node query(int i)
	{
		Node ls=query(1,0,n,0,i-1);
		Node rs=query(1,0,n,i,n);
	//	if(i==3)cout<<ls.mi<<" "<<ls.mx<<" "<<rs.mi<<" "<<rs.mx<<endl;
		return Node(rs.mi-ls.mx,rs.mx-ls.mi);
	}
}s;
int abs1(int x){return x>0?x:-x;}
int main()
{
//	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i].first),w[i].second=i;
	sort(w+1,w+n+1);
	s.build(1,0,n);s.build(1,0,n);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&w[r+1].first==w[l].first)++r;
		for(int i=l;i<=r;i++)
		{
			Node t=s.query(w[i].second);
			if(abs1(t.mi)%2==1)--t.mi;if(abs1(t.mx)%2==1)--t.mx;
			ans[w[i].second]=max(ans[w[i].second],max(abs1(t.mi),abs1(t.mx))/2);
//		for(int j=1;j<=n;j++)cout<<query(1,0,n,j,j).mi-query(1,0,n,j-1,j-1).mi<<" ";puts("");
		}
		for(int i=l;i<=r;i++)s.update(1,0,n,w[i].second,n,-2);
		for(int i=l;i<=r;i++)
		{
			s.update(1,0,n,w[i].second,n,2);
			Node t=s.query(w[i].second);
			if(abs1(t.mi)%2==1)--t.mi;if(abs1(t.mx)%2==1)--t.mx;
			ans[w[i].second]=max(ans[w[i].second],max(abs1(t.mi),abs1(t.mx))/2);
			s.update(1,0,n,w[i].second,n,-2);	
		}		
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}