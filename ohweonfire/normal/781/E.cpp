// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;

int h,w,n,u[100111],l[100111],r[100111],ord[100111],s[100111];
bool cmp(int x,int y){return u[x]<u[y];}

#define lson (t<<1)
#define rson ((t<<1)|1)
struct SGT
{
	struct node
	{
		int l,r;
		set<int> val;
	}seg[400111];
	void build(int l,int r,int t=1)
	{
		seg[t].l=l;seg[t].r=r;seg[t].val.insert(1);
		if(l==r)return;
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
	}
	void set(int l,int r,int v,int add,int t=1)
	{
//		printf("Set %d %d %d %d %d\n",l,r,v,add,t);
		if(seg[t].l==l&&seg[t].r==r)
		{
			if(add==1)seg[t].val.insert(v);
			else seg[t].val.erase(v);
			return;
		}
		int mid=(seg[t].l+seg[t].r)>>1;
		if(r<=mid)set(l,r,v,add,lson);
		else if(l>mid)set(l,r,v,add,rson);
		else
		{
			set(l,mid,v,add,lson);
			set(mid+1,r,v,add,rson);
		}
	}
	int query(int v,int t=1)
	{
		if(seg[t].l==seg[t].r)return *seg[t].val.rbegin();
		int mid=(seg[t].l+seg[t].r)>>1;
		if(v<=mid)return max(*seg[t].val.rbegin(),query(v,lson));
		else return max(*seg[t].val.rbegin(),query(v,rson));
	}
}sgt;

int dp[100111],tmp[100111];
vector<int> chg[100111];
void go(int *a,int *b)
{
	for(int i=1;i<=n;i++)tmp[i]=a[i];
	for(int i=1;i<=n;i++)a[i]=tmp[b[i]];
}
void fall(int x,int num)
{
	int nxt=sgt.query(x);
//	printf("fall %d nxt= %d num= %d\n",x,nxt,num);
	if(num>=mod)num-=mod;
	dp[nxt]+=num;
	if(dp[nxt]>=mod)dp[nxt]-=mod;
}
int main()
{
	get3(h,w,n);
	for(int i=1;i<=n;i++)
	{
		ord[i]=i;
		get3(u[i],l[i],r[i]);get1(s[i]);s[i]+=u[i];
	}
	n++;ord[n]=n;u[n]=0;l[n]=1;r[n]=w;s[n]=h+100;
	n++;ord[n]=n;u[n]=h+1;l[n]=1;r[n]=w;s[n]=0;
	sort(ord+1,ord+n+1,cmp);
	go(u,ord);go(l,ord);go(r,ord);go(s,ord);
	for(int i=1;i<n;i++)if(u[i]>u[i+1])for(;;);
	
	for(int i=1;i<n;i++)
	{
		int id=lower_bound(u+1,u+n+1,s[i]+1)-u-1;
//		printf("set %d %d\n",i,id);
		chg[id].pb(i);
	}
	sgt.build(1,w);
	dp[n]=n;
	for(int i=n;i>1;i--)
	{
//		printf("%d dp %d\n",i,dp[i]);
		if(i<n)sgt.set(l[i],r[i],i,-1,1);
		for(int j=0;j<(int)chg[i].size();j++)
		{
			int id=chg[i][j];if(id==i)continue;
			sgt.set(l[id],r[id],id,1);
		}
		if(i==n)for(int j=1;j<=w;j++)fall(j,1);
		else
		{
			if(l[i]==1)fall(r[i]+1,dp[i]*2);
			else if(r[i]==w)fall(l[i]-1,dp[i]*2);
			else
			{
				fall(l[i]-1,dp[i]);
				fall(r[i]+1,dp[i]);
			}
		}
	}
	printendl(dp[1]);
	return 0;
}