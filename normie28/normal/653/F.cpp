
// Problem : F. Paper task
// Contest : Codeforces - IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
// URL : https://codeforces.com/problemset/problem/653/F
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
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

//---------END-------//
const int N=500010;
int cg[200],n,now[N];
char s[N];
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
ll sum[N<<2],mn[N<<2];
map<int,vector<int>>v;
void build(int l,int r,int rt) {
    if (l==r) {
        mn[rt]=sum[rt]=cg[cg[s[l]]];
        //printf("l:%d v:%d\n",l,mn[rt]);
        return ;
    }
    int m=(l+r)>>1;
    build(lson),build(rson);
    mn[rt]=min(mn[rt<<1|1],sum[rt<<1|1]+mn[rt<<1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int fg,sm;
void qry(int L,int R,int l,int r,int rt) {
    if(fg) return;
    int m=(l+r)>>1;
    if (L<=l&&r<=R) {
        if(mn[rt]+sm>=0) {
            sm+=sum[rt];
            return ;
        }
        if (l==r) {
            if(sm+mn[rt]<0) fg=l;
            return ;
        }
        if(mn[rt<<1|1]+sm<0&&!fg) qry(L,R,rson);
        else sm+=sum[rt<<1|1];
        if(mn[rt<<1]+sm<0&&!fg) qry(L,R,lson);
    }
    if (m<R) qry(L,R,rson);
    if (L<=m) qry(L,R,lson);
}
 
struct SuffixAutoMaton{
    int ch[N<<1][2],fa[N<<1],l[N<<1],size[N<<1],k[N<<1],c[N<<1],pos[N<<1];
    map<int,int>mp[N<<1];
    int last,tot;
    void init() {last=tot=1;memset(ch[1],0,sizeof ch[1]);}
    void ins(int c,int pp) {
        int p=last,np=++tot;last=np;l[np]=l[p]+1;
        memset(ch[tot],0,sizeof ch[tot]);
        for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
        if(!p)fa[np]=1;
        else {
            int q=ch[p][c];
            if(l[p]+1==l[q])fa[np]=q;
            else {
                int nq=++tot;l[nq]=l[p]+1;
                memcpy(ch[nq],ch[q],sizeof(ch[q]));
                fa[nq]=fa[q];fa[q]=fa[np]=nq;
                for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
            }
        }
        size[np]=1;
        pos[np]=pp;
    }
    void build() {
        init();
        n=strlen(s+1);
        for(int i=1;i<=n;i++) ins(cg[s[i]],i);
        for(int i=1;i<=tot;i++) c[l[i]]++;
        for(int i=1;i<=tot;i++) c[i]+=c[i-1];
        for(int i=1;i<=tot;i++) k[c[l[i]]--]=i;
        for(int id=tot;id;id--) {
            int i=k[id];
            pos[fa[i]]=pos[i];
        }
        ll ans=0;
        for(int i=2;i<=tot;i++) {
            if(s[pos[i]]==')') continue;
            //printf("i:%d\n",i);
            fg=sm=0;
            qry(1,pos[i],1,n,1);//puts("A");
            //printf("i:%d fg:%d pos:%d len:%d lfa:%d\n",i,fg,pos[i],l[i],l[fa[i]]);
            int val=now[pos[i]+1];
            int L=max(pos[i]-l[i]+1,fg);
            int R=pos[i]-l[fa[i]];
            auto &x=v[val];
            //printf("L:%d R:%d val:%d\n",L,R,upper_bound(x.begin(),x.end(),R)-lower_bound(x.begin(),x.end(),L));
            if(L<=R) ans+=upper_bound(x.begin(),x.end(),R)-lower_bound(x.begin(),x.end(),L);
            //puts("");
        }
        cout<<ans<<endl;
    }
}sam;
 
int main(){
    fio;
    cg['(']=0;cg[')']=1;cg[0]=1,cg[1]=-1;
    cin>>n>>s+1;
    reverse(s+1,s+1+n);
    for(int i=n;i;i--) {
        now[i]=now[i+1]+cg[cg[s[i]]];
        v[now[i]].push_back(i);
    }
    build(1,n,1);
    for(auto &i:v) sort(i.second.begin(),i.second.end());
    sam.build();
}