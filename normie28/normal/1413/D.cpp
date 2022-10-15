/*New, shiny, hand-crafted segtree template.Perfect for use in any online contest.Tested with Codeforces Edu and library-checker. */
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
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define size siz
//---------END-------//
ll n,m,i,j,k,t;
ll a,b,u,v,ress=0;
ll events[200001],res[200001];
set<ll> buys,adds;
vector<ll> lis;
int main(){
    fio;
    cin>>n;
    for (i=1;i<=2*n;i++)
    {
        char c; 
        cin>>c;
        if (c=='+') 
        {
            events[i]=-1; 
            adds.insert(i);
            
        }else{ 
            cin>>events[i]; 
            buys.insert(i); 
            lis.push_back(i);
            
        }
        
    } 
    sort(lis.begin(),lis.end(),[](ll a, ll b){return (events[a]<events[b]);});
    for (i=0;i<n;i++)
    {
        ll cur=lis[i],lb;
    //    cout<<cur<<endl;
        auto it=buys.lower_bound(cur);
        if (it==buys.begin()) lb=0; 
        else lb=(*(--it));
    //    cout<<lb<<endl;
        auto it2=adds.lower_bound(lb);
        if (it2==adds.end()) return cout<<"NO",0;
        ll chosen=(*it2);
        if (chosen>cur) return cout<<"NO",0;
        res[chosen]=i+1;
        buys.erase(cur);
        adds.erase(chosen);
        
    }
    cout<<"YES\n";
    for (i=1;i<=2*n;i++) if (res[i]) cout<<res[i]<<' ';
    
}