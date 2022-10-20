#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define int long long
using namespace std;
const int N=2e5+5;
const int inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,i,lastans;
struct Segment_Tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4];
	void change(int w,int l,int r,int x,int y)
	{
		if (l==r) return void(t[w]=y);
		if (x<=mid) change(ls,l,mid,x,y);
			   else change(rs,mid+1,r,x,y);
		t[w]=min(t[ls],t[rs]);
	}
	void change(int x,int y) {//xy 
		change(1,0,n,x,y);
	}
	int QueryPreMin(int w,int l,int r,int x)
	{
		if (l>x) return inf;
		if (r<=x) return t[w];
		return min(QueryPreMin(ls,l,mid,x),QueryPreMin(rs,mid+1,r,x));
	}
	int QueryPreMin(int x) {//minmex 
		return QueryPreMin(1,0,n,x);
	}
	int Query(int w,int l,int r,int x)
	{
		if (l==r) return l;
		if (t[ls]<x) return Query(ls,l,mid,x);
			    else return Query(rs,mid+1,r,x);
	}
	int Query(int x) {//xxmex 
		return Query(1,0,n,x);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
struct node{int l1,r1,l2,r2,suml,sumr,sum;}null;
vector<node>a[N];
int b[N];
int calc(int l,int r,node a)
{
	int L1=max(l,a.l1),R1=min(r,a.r1);
	int L2=max(l,a.l2),R2=min(r,a.r2);
	if (L1>R1||L2>R2) return 0;
	return (R1-L1+1)*(R2-L2+1);
}
void push(int k,int l1,int r1,int l2,int r2)
{
	node lst=a[k].empty()?null:a[k].back();
	a[k].push_back((node){l1,r1,l2,r2,lst.suml+(l1-1)*(r2-l2+1),lst.sumr+r1*(r2-l2+1),lst.sum+r2-l2+1});
}
int solve(int l,int r,int k,int x)
{
	int pos1=lower_bound(a[k].begin(),a[k].end(),(node){0,l,0,0,0,0,0},[&](const node &a,const node &b){
		return a.r1<b.r1;
	})-a[k].begin()-1;
	if (pos1>x) return 0;
	int pos2=lower_bound(a[k].begin(),a[k].end(),(node){l,0,0,0,0,0,0},[&](const node &a,const node &b){
		return a.l1<b.l1;
	})-a[k].begin()-1;
	pos2=min(pos2,x);
//	print(x,' '),print(pos1,','),print(pos2,':');
	return a[k][x].sumr-(pos1>=0?a[k][pos1].sumr:0)-(a[k][pos2].sum-a[k][pos1].sum)*(l-1)-(a[k][x].suml-(pos2>=0?a[k][pos2].suml:0));
}
int query(int l,int r,int k)
{
	int L=t.QueryPreMin(k)+1,R=min(t.QueryPreMin(k-1),i);
//	for (auto i:a[k]) print(i.l1,' '),print(i.r1,' '),print(i.l2,' '),print(i.r2);
	int ans=0;
	if (L<=R) ans=calc(l,r,(node){L,R,b[L],n,0,0,0});
//	for (auto i:a[k]) ans+=calc(l,r,i);
//	return ans;
//	print(ans,',');
//	print(L,' '),print(R);
	int m=a[k].size();
	L=lower_bound(a[k].begin(),a[k].end(),(node){0,0,0,l,0,0,0},[&](const node &a,const node &b){
		return a.r2<b.r2;
	})-a[k].begin();
	R=upper_bound(a[k].begin(),a[k].end(),(node){0,0,r,0,0,0,0},[&](const node &a,const node &b){
		return a.l2<b.l2;
	})-a[k].begin()-1;
	if (L==m||R<0) return ans;
	if (L==R) return ans+calc(l,r,a[k][L]);
	ans+=calc(l,r,a[k][L])+calc(l,r,a[k][R]);
//	print(ans,':'),print(L,' '),print(R);
	return ans+(L<=R?solve(l,r,k,R-1)-solve(l,r,k,L):0);
}
void put(int x,int now)
{
	int mex=t.Query(x),L=t.QueryPreMin(mex)+1;
	if (L<x)
	{
		push(mex,L,x-1,b[L],now-1);
		b[L]=now;
	}
}

signed main()
{
	n=read();
	for (i=1,lastans=0;i<=n;i++)
	{
		int a=read(),l=read(),r=read(),k=read();
		a=(a+lastans)%(n+1),l=(l+lastans)%i+1,r=(r+lastans)%i+1,k=(k+lastans)%(n+1);
		if (l>r) swap(l,r);
		int L=t.QueryPreMin(a)+1,R=min(t.QueryPreMin(a-1),i-1);
		t.change(a,i);
//		print(a,' '),print(l,' '),print(r,' '),print(k);
//		print(L,' '),print(R);
		if (L<=R)
		{
			push(a,L,R,b[L],i-1);
			put(L,i);
			while (L<=R)
			{
				int mex=t.Query(L);
				int x=min(R,t.QueryPreMin(mex-1));
				b[L]=i;
				L=x+1;
			}
		}
		b[i]=i;
		put(i,i);
		print(lastans=query(l,r,k));
	}
	
	return 0;
}