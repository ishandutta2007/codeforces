#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
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

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
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
struct seg{
    int val[800011];
    int lazy[800011];
    void reset(int c, int l, int r) {
        val[c]=l;
        lazy[c]=0;
        if (l<r)
        {
            int mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
        }
    }
    void flusha(int c) {
        val[(c<<1)]+=lazy[c];
        val[(c<<1)+1]+=lazy[c];
        lazy[(c<<1)]+=lazy[c];
        lazy[(c<<1)+1]+=lazy[c];
        lazy[c]=0;
    }
    void upd(int c, int l, int r, int tl, int tr, int x) {
        if ((l>tr)or(r<tl)) return;
        else if ((l>=tl)and(r<=tr)) {
            val[c]+=x;
            lazy[c]+=x;
        }
        else {
            flusha(c);
            int mid=(l+r)/2;
            upd((c<<1), l, mid, tl, tr, x);
            upd((c<<1)+1, mid+1, r, tl, tr, x);
            val[c]=min(val[(c<<1)],val[(c<<1)+1]);
        }
    }
    int find(int c, int l, int r, int x) {
        if (l==r) return l;
        int mid=(l+r)/2;
        flusha(c);
        if (val[(c<<1)+1]<=x) return find((c<<1)+1, mid+1, r, x);
        else return find((c<<1), l, mid, x);
    }
};
seg st;
vector<int> vec;
vector<int> vec2;
set<int> sl;
ll n,m,i,j,k,t,t1,u,v,a,b;
int xrr[200001];
int yrr[200001];
ll fac[400001];
ll inv[400001];
set<pii(int)> lmao;
int main()
{
	fio;
    st.reset(1,1,200000);
    fac[0]=1;
    inv[0]=1;
    for (i=1;i<=400000;i++) { fac[i] = fac[i-1]*i; fac[i]%=MOD; inv[i]=INV(fac[i],MOD); }
    cin>>t;
    for (t1=0;t1<t;t1++) {
        cin>>n>>m;
        vec.clear();
        for (i=1;i<=m;i++) cin>>xrr[i]>>yrr[i];
        
        for (i=m;i>=1;i--) {
            xrr[i]=st.find(1,1,200000,yrr[i]);
            st.upd(1,1,200000,xrr[i]+1,200000,-1);
            vec.push_back(xrr[i]);
        }

        

        for (i=m;i>=1;i--) {
            st.upd(1,1,200000,xrr[i]+1,200000,1);
        }


        u=0;
        sl.clear();
        lmao.clear();
        int l,r;
        sort(vec.begin(),vec.end());
        for (i=0;i<m;i++) {
            if (i==0) {
                l=r=vec[0];
            }
            else if (vec[i]==vec[i-1]+1) r=vec[i];
            else {
                sl.insert(l-1);
                sl.insert(r+1);
                if (l>1 && r<n) lmao.insert({l-1,r+1});
                l=r=vec[i];
            }
        }

            if (m) { 

                sl.insert(l-1);
                sl.insert(r+1);
                if (l>1 && r<n) lmao.insert({l-1,r+1});
                // l=r=vec[i];

            }


        for (i=1;i<=m;i++) {
            auto it = sl.lower_bound(xrr[i]);
            auto it2 = it;
            it2--;
            auto it3 = lmao.find({*it2,*it});
            if (it3 != lmao.end()) lmao.erase(it3);
            lmao.insert({xrr[i],*it});
            sl.insert(xrr[i]);
            // cout<<' '<<endl;
        }
        
        u = lmao.size();
        a = 1;
        a*=fac[n-1-u+n];
        a*=inv[n-1-u]; a%=MOD;
        a*=inv[n]; a%=MOD;
        // n-1-u over n+1 
        cout<<a<<endl;
    }
}

// Normie28;