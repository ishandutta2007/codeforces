// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;
#define ls (t<<1)
#define rs ((t<<1)|1)

int seq[maxn],tot;
LL nv[maxn];
namespace sgt
{
	struct node
	{
		LL mn,dlt;
		node(){mn=dlt=0;}
		void add(LL v)
		{
			mn+=v;
			dlt+=v;
		}
	};
	node seg[maxn*3];
	void push(int t)
	{
		if(seg[t].dlt)
		{
			seg[ls].add(seg[t].dlt);
			seg[rs].add(seg[t].dlt);
			seg[t].dlt=0;
		}
	}
	void modify(int p,LL v,int tl,int tr,int t)
	{
		if(tl==tr)
		{
			seg[t].mn=v;
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(p<=mid)modify(p,v,tl,mid,ls);
		else modify(p,v,mid+1,tr,rs);
		seg[t].mn=min(seg[ls].mn,seg[rs].mn);
	}
	LL query(int p,int tl,int tr,int t)
	{
		if(tl==tr)return seg[t].mn;
		int mid=(tl+tr)>>1;
		if(p<=mid)return query(p,tl,mid,ls)+seg[t].dlt;
		else return query(p,mid+1,tr,rs)+seg[t].dlt;
	}
	
	void add(int l,int r,int v,int tl,int tr,int t)
	{
		if(l<=tl&&tr<=r)
		{
			seg[t].add(v);
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(l<=mid)add(l,r,v,tl,mid,ls);
		if(r>mid)add(l,r,v,mid+1,tr,rs);
		seg[t].mn=min(seg[ls].mn,seg[rs].mn);
	}
	
	void dfs(int l,int r,int tl,int tr,int t)
	{
		if(seg[t].mn>0)return;
		if(tl==tr)
		{
			seq[++tot]=tl;
			nv[tot]=seg[t].mn;
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(l<=mid)dfs(l,r,tl,mid,ls);
		if(r>mid)dfs(l,r,mid+1,tr,rs);
	}
}

LL bad[12]={};
int n,q,a[maxn],val[maxn];
set<int> st;

LL query(int pos)
{
	set<int>::iterator it=st.upper_bound(pos);it--;
	pos=*it;
	return bad[val[pos]]-sgt::query(pos,1,n,1);
}
void extract(int i)
{
	if(i>n||st.find(i)!=st.end())return;
	LL v=query(i);st.insert(i);
	val[i]=1;while(bad[val[i]]<v)val[i]++;
	sgt::modify(i,bad[val[i]]-v,1,n,1);
}
void assign(int l,int r,int v)
{
	extract(r+1);
	for(set<int>::iterator it=st.lower_bound(l),it2;it!=st.end()&&(*it)<=r;)
	{
		sgt::modify(*it,Linf,1,n,1);
		it2=it;it++;st.erase(it2);
	}
	st.insert(l);
	val[l]=0;while(bad[val[l]]<v)val[l]++;
	sgt::modify(l,bad[val[l]]-v,1,n,1);
}
void add(int l,int r,int v)
{
	extract(l);extract(r+1);
	while(true)
	{
		sgt::add(l,r,-v,1,n,1);tot=0;sgt::dfs(l,r,1,n,1);
		bool ok=1;
		for(int _=1,i;_<=tot;_++)
		{
			i=seq[_];
			LL cur=bad[val[i]]-nv[_];
			while(bad[val[i]]<cur)val[i]++;
			if(bad[val[i]]==cur)
			{
				ok=0;
				val[i]++;
			}
			sgt::modify(i,bad[val[i]]-cur,1,n,1);
		}
		if(ok)break;
	}
}

int main()
{
	bad[0]=1;for(int i=1;i<=11;i++)bad[i]=bad[i-1]*42;
	get2(n,q);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		while(bad[val[i]]<a[i])val[i]++;
		sgt::modify(i,bad[val[i]]-a[i],1,n,1);
		st.insert(i);
	}
	
	for(int i=1,tp,x,y,z;i<=q;i++)
	{
		get2(tp,x);
		if(tp==1)printf("%lld\n",query(x));
		else if(tp==2)
		{
			get2(y,z);
			assign(x,y,z);
		}
		else if(tp==3)
		{
			get2(y,z);
			add(x,y,z);
		}
	}
	return 0;
}