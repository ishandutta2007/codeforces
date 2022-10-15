#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
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
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
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
#define MOD (ll(998244353))
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
//---------END-------//
#endif
int sta[600001];
struct seg
{
    int val[600011][5]; // max, min, 1+2, 2+3, 1+2+3
    int lazy[600011];
    void merg(int c)
    {
        val[c][0]=max(val[(c<<1)][0],val[(c<<1)+1][0]);
        val[c][1]=min(val[(c<<1)][1],val[(c<<1)+1][1]);
        val[c][2]=max(val[(c<<1)][2],val[(c<<1)+1][2]);
        val[c][3]=max(val[(c<<1)][3],val[(c<<1)+1][3]);
        val[c][4]=max(val[(c<<1)][4],val[(c<<1)+1][4]);
        val[c][2]=max(val[c][2],val[(c<<1)][0]-2*val[(c<<1)+1][1]);
        val[c][3]=max(val[c][3],-2*val[(c<<1)][1]+val[(c<<1)+1][0]);
        val[c][4]=max(val[c][4],val[(c<<1)][2]+val[(c<<1)+1][0]);
        val[c][4]=max(val[c][4],val[(c<<1)+1][3]+val[(c<<1)][0]);
    }
    void flush(int c)
    {
        val[(c<<1)][0]+=lazy[c];
        val[(c<<1)][1]+=lazy[c];
        val[(c<<1)][2]-=lazy[c];
        val[(c<<1)][3]-=lazy[c];
        lazy[(c<<1)]+=lazy[c];
        val[(c<<1)+1][0]+=lazy[c];
        val[(c<<1)+1][1]+=lazy[c];
        val[(c<<1)+1][2]-=lazy[c];
        val[(c<<1)+1][3]-=lazy[c];
        lazy[(c<<1)+1]+=lazy[c];
        lazy[c]=0;
    }
    void reset(int c, int l, int r)
    {
        lazy[c]=0;
        if (l==r)
        {
            val[c][0]=sta[l];
            val[c][1]=sta[l];
            val[c][2]=-sta[l];
            val[c][3]=-sta[l];
            val[c][4]=0;
        }
        else
        {
            int mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
            merg(c);
        }
    }
    void upd(int c, int l, int r, int tl, int tr, int d)
    {
        if ((r<tl)or(tr<l)) return;
        if ((l>=tl)and(r<=tr))
        {
            val[c][0]+=d;
            val[c][1]+=d;
            val[c][2]-=d;
            val[c][3]-=d;
            lazy[c]+=d;
        }
        else
        {
            flush(c);
            int mid=(l+r)/2;
            upd((c<<1),l,mid,tl,tr,d);
            upd((c<<1)+1,mid+1,r,tl,tr,d);
            merg(c);
        }
    }
    void debug(int c, int l, int r)
    {
        cout<<"   --- --- ---   \n";
        cout<<"Debug node "<<c<<endl;
        cout<<"Debug range "<<l<<' '<<r<<endl;
        cout<<val[c][0]<<' '<<val[c][1]<<' '<<val[c][2]<<' '<<val[c][3]<<' '<<val[c][4]<<endl;
        cout<<lazy[c]<<endl;
        cout<<"   --- --- ---   \n";
        int mid=(l+r)/2;
        if (l<r)
        {
            debug((c<<1),l,mid);
            debug((c<<1)+1,mid+1,r);
        }
    }
};
seg st;
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
string s;
int main()
{
	fio;
    cin>>n>>m;
    cin>>s;
    for (i=0;i<2*n-2;i++) if (s[i]=='(') sta[i+1]=sta[i]+1; else sta[i+1]=sta[i]-1;
    st.reset(1,0,2*n-2);
    //    cout<<s<<endl;
        cout<<st.val[1][4]<<endl;
    for (i=1;i<=m;i++)
    {
        cin>>u>>v;
        if (u>v) swap(u,v);
        u--;
        v--;
    //    cout<<1<<' '<<0<<' '<<2*n-2<<' '<<u+1<<' '<<v<<' ';
        if (s[u]=='(') st.upd(1,0,2*n-2,u+1,v,-2); 
        else st.upd(1,0,2*n-2,u+1,v,2);
    //    if (s[u]=='(') cout<<2<<endl; else cout<<-2<<endl;
        swap(s[u],s[v]);
    //    cout<<s<<endl;
        cout<<st.val[1][4]<<endl;
    //    st.debug(1,0,2*n-2);
    }

}