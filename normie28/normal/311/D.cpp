/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(95542721))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
ll cube(ll x)
{
	ll a=1;
	a*=x;
	a%=MOD;
	a*=x;
	a%=MOD;
	a*=x;
	a%=MOD;
	return a;
}
//---------END-------//
struct
{
    long long num[48];
    int flag;
}tree[400010];
 
long long temp[48],a[100010];
 
void change(int l,int r,int x,int pos)
{
    for(int i=0;i<48;i++)
        temp[i]=tree[pos].num[(i+x)%48];
    for(int i=0;i<48;i++)
        tree[pos].num[i]=temp[i];
}
 
void push_down(int l,int r,int pos)
{
    tree[pos*2].flag+=tree[pos].flag;
    tree[pos*2+1].flag+=tree[pos].flag;
    int mid=(l+r)/2;
    change(l,mid,tree[pos].flag,pos*2);
    change(mid+1,r,tree[pos].flag,pos*2+1);
    tree[pos].flag=0;
}
 
void build(int l,int r,int pos)
{
    tree[pos].flag=0;
    if(l==r)
    {
        tree[pos].num[0]=a[l];
        for(int i=1;i<48;i++)
            tree[pos].num[i]=(tree[pos].num[i-1]*(tree[pos].num[i-1]*tree[pos].num[i-1]%MOD))%MOD;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,pos*2);
    build(mid+1,r,pos*2+1);
    for(int i=0;i<48;i++)
        tree[pos].num[i]=(tree[pos*2].num[i]+tree[pos*2+1].num[i])%MOD;
}
 
void update(int l,int r,int x,int y,int pos)
{
    if(l>=x&&r<=y)
    {
        tree[pos].flag++;
        change(l,r,1,pos);
        return;
    }
    if(tree[pos].flag)
        push_down(l,r,pos);
    int mid=(l+r)/2;
    if(x<=mid)
        update(l,mid,x,y,pos*2);
    if(y>mid)
        update(mid+1,r,x,y,pos*2+1);
    for(int i=0;i<48;i++)
        tree[pos].num[i]=(tree[pos*2].num[i]+tree[pos*2+1].num[i])%MOD;
}
 
long long query(int l,int r,int x,int y,int pos)
{
    if(l>=x&&r<=y)
        return tree[pos].num[0];
    if(tree[pos].flag)
        push_down(l,r,pos);
    int mid=(l+r)/2;
    long long res=0;
    if(x<=mid)
        res=res+query(l,mid,x,y,pos*2);
    if(y>mid)
        res=(res+query(mid+1,r,x,y,pos*2+1))%MOD;
    return res;
}
 
int main()
{
	fio;
    int n,m,t,l,r;
	cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
    build(1,n,1);
	cin>>m;
    for(int i=1;i<=m;i++)
    {
		cin>>t>>l>>r;
        if(t==1)
            cout<<query(1,n,l,r,1)<<endl;
        else
            update(1,n,l,r,1);
    }
}