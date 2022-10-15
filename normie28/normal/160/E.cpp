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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int maxN=1e5+1;
 
struct nod{
    int l,r,t,idx;
}v[2*maxN];
 
bool cmp(nod a,nod b){
    if(a.l==b.l)
        return a.idx<b.idx;
    return a.l<b.l;
}
 
int n,m;
int sol[maxN];
 
int times[2*maxN];
 
struct aintNode{
    int maxx;
    int idx;
}aint[8*maxN];
 
void update(int node,int st,int dr,int pos,int rigValue,int ind){
    if(st==dr){
        aint[node].maxx=rigValue;
        aint[node].idx=ind;
        return;
    }
 
    int mij=(st+dr)/2;
    if(pos<=mij)
        update(2*node,st,mij,pos,rigValue,ind);
    else
        update(2*node+1,mij+1,dr,pos,rigValue,ind);
 
    aint[node].maxx=max(aint[2*node].maxx,aint[2*node+1].maxx);
}
 
int query(int node,int st,int dr,int pos,int rigValue){
    if(rigValue>aint[node].maxx) // nu e in subarb
        return -1;
 
    if(st==dr)
        return aint[node].idx;
 
    int res=-1;
    int mij=(st+dr)/2;
 
    if(pos<=mij){
        res=query(2*node,st,mij,pos,rigValue);
        if(res>0)
            return res;
    }
    return query(2*node+1,mij+1,dr,pos,rigValue);
}
 
int main(){
    fio;
    cin>>n>>m;
    for(int i=1;i<=n+m;i++){
        cin>>v[i].l>>v[i].r>>v[i].t;
        v[i].idx=i;
        times[i]=v[i].t;
    }
 
    sort(times+1,times+n+m+1);
    sort(v+1,v+n+m+1,cmp);
 
    for(int i=1;i<=n+m;i++){
        int poz=lower_bound(times+1,times+n+m+1,v[i].t)-times; //BS
 
        if(v[i].idx<=n) {
            update(1,1,n+m,poz,v[i].r,v[i].idx);
        } else {
            sol[v[i].idx-n]=query(1,1,n+m,poz,v[i].r);
        }
    }
 
    for(int i=1;i<=m;i++)
        cout<<sol[i]<<' ';
}