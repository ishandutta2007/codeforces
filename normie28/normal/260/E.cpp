/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long LL;
 #define data datum
int n,flag,p[10],b[10],c[10],X[3],Y[3];
struct data
{
	int x,y;
}a[100010],d[100010];
struct st
{
	int l,r;
	vector <int > v;
}t[400010];
vector <int > e;
 
bool cmpx(data x,data y){return x.x<y.x;}
bool cmpy(data x,data y){return x.y<y.y;}
 
void build(int k,int l,int r,int x,int y)
{
    t[k].l=l;t[k].r=r;
    int tmp=0,mid=(l+r)/2;
    for(int i=x;i<=y;i++)
    {
        t[k].v.push_back(a[i].y);
        if(a[i].x<=e[mid]) tmp=i;
    }
    sort(t[k].v.begin(),t[k].v.end());
    if(l==r)return;
    build(k<<1,l,mid,x,tmp);
    build(k<<1|1,mid+1,r,tmp+1,y);
}
 
int query(int k,int x,int y)
{
    if(e[t[k].r]<=x) return upper_bound(t[k].v.begin(),t[k].v.end(),y)-t[k].v.begin();
    int tmp=query(k<<1,x,y);
    if(e[t[k<<1|1].l]<=x) tmp+=query(k<<1|1,x,y);
    return tmp;
}
 
bool check()
{
	int u[4],v[4];
	u[1]=p[c[1]]+p[c[2]]+p[c[3]];
	u[2]=p[c[4]]+p[c[5]]+p[c[6]];
	u[3]=p[c[7]]+p[c[8]]+p[c[9]];
	X[1]=a[u[1]].x,X[2]=a[u[2]+u[1]].x;
	if (a[u[1]].x==a[u[1]+1].x) return false;
	if (a[u[2]+u[1]].x==a[u[2]+u[1]+1].x) return false;
	v[1]=p[c[1]]+p[c[4]]+p[c[7]];
	v[2]=p[c[2]]+p[c[5]]+p[c[8]];
	v[3]=p[c[3]]+p[c[6]]+p[c[9]];
	Y[1]=d[v[1]].y,Y[2]=d[v[2]+v[1]].y;
	if (d[v[1]].y==d[v[1]+1].y) return false;
	if (d[v[2]+v[1]].y==d[v[2]+v[1]+1].y) return false;
	if (query(1,X[1],Y[1])!=p[c[1]]) return false;
	if(query(1,X[2],Y[1])!=p[c[1]]+p[c[4]]) return false;
    if(query(1,X[1],Y[2])!=p[c[1]]+p[c[2]]) return false;
    if(query(1,X[2],Y[2])!=p[c[1]]+p[c[2]]+p[c[4]]+p[c[5]]) return false;
    printf("%0.1lf %0.1lf\n%0.1lf %0.1lf\n",(double)X[1]+0.5,(double)X[2]+0.5,(double)Y[1]+0.5,(double)Y[2]+0.5);
    return true;
}
 
void pp(int x)
{
	if (flag==1) return ;
	if (x==10){if (check()) flag=1;return ;}
	for (int i=1;i<=9;i++)
		if (!b[i]) c[x]=i,b[i]=1,pp(x+1),b[i]=0;
	if (flag==1) return ;
}
 
int main()
{
    fio;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y,e.push_back(a[i].x),
		d[i].x=a[i].x,d[i].y=a[i].y;
	sort(e.begin(),e.end());
	e.erase(unique(e.begin(),e.end()),e.end());
	sort(a+1,a+1+n,cmpx);
	sort(d+1,d+1+n,cmpy);
	build(1,0,e.size()-1,1,n);
	for (int i=1;i<=9;i++)
		cin>>p[i];
	memset(b,0,sizeof(b));
	flag=0;
	pp(1);
	if (flag!=1) cout<<-1<<endl;
}