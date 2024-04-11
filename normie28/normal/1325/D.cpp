#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "exp.inp"
#define FILE_OUT "exp.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
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
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
ll n,m,i,j,k,t,t1,p,rcnt[100001],res[100001],used[100001],maxx=-100,istree,aad,bad,resa,resb,tog[64];
void fail()
{
    cout<<3<<endl<<n<<' '<<(m-n)/2<<' '<<(m-n)/2; exit(0);
}
int main(){
    fio;
    cin>>n>>m;
    if ((m==0)and(n==0)) cout<<0;
    else if (m==n) cout<<1<<endl<<n;
    else if (m<n) cout<<-1;
    else if ((m-n)%2) cout<<-1;
    else 
    {
        aad=n;
        bad=m;
        resa=0;
        resb=0;
        int cnt0=0,st=0;
        for (i=0;i<63;i++)
        {
            int cura=aad%2;
            int curb=bad%2;
            if (cura==curb)
            {
                if (st==1) fail();
                if (cura==1) st=0; else st=-1;
            }
            else 
            {
                if (st==0) fail();
                if (tog[i-1]==0) tog[i-1]=2;
                if (curb==0) st=1; else st=-1;
            }
            tog[i]=cura;
            aad/=2;
            bad/=2;
        }
        for (i=62;i>=0;i--) {resa*=2; resb*=2; if (tog[i]>=1) resa++; if (tog[i]==2) resb++;}
        cout<<2<<endl<<resa<<' '<<resb;
    }
    
}