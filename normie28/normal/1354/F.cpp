/*
khoi orz, go check out his algo
-normie-
Tested with library-checker.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define prev prv
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
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define pi 3.1415926535897
//------START-----------//
ll n,m,i,j,k,u,v,t,t1,a,b,l,r,ress=0;
ll dp[76][76],ch[76][76];
vector<plll> mons;
vector<ll> seq,buc1,buc0;
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n>>k;
        mons.clear();
        for (i=1;i<=n;i++)
        {
            cin>>a>>b;
            mons.push_back({i-1,{a,b}});
        }
            sort(mons.begin(),mons.end(),[](plll a, plll b){return (a.p3<b.p3);});
        for (i=n;i>=0;i--) for (j=k;j>=0;j--)
        {
            if (i==n)
            {
                if (j==k)
                {
                    dp[i][j]=0;
                    ch[i][j]=0;
                }
                else
                {
                    dp[i][j]=-1e18;
                    ch[i][j]=0;
                }
            }
            else
            {
                dp[i][j]=dp[i+1][j]+(mons[i].p3)*(k-1);
                ch[i][j]=0;
                if ((j<k)and(dp[i][j]<dp[i+1][j+1]+mons[i].p2+(mons[i].p3)*j))
                {
                    ch[i][j]=1;
                    dp[i][j]=dp[i+1][j+1]+mons[i].p2+(mons[i].p3)*j;
                }
            }
    //        cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<ch[i][j]<<endl;
        }
        seq.clear();
        buc0.clear();
        buc1.clear();
        j=0;
        for (i=0;i<n;i++)
        {
            if (ch[i][j])
            {
                buc1.push_back(mons[i].p1);
                j++;
            }
            else
            {
                buc0.push_back(mons[i].p1);
            }
        }
        for (i=0;i<buc1.size()-1;i++) seq.push_back(buc1[i]+1);
        for (i=0;i<buc0.size();i++) {seq.push_back(buc0[i]+1); seq.push_back(-buc0[i]-1);}
        seq.push_back(buc1[buc1.size()-1]+1);
        cout<<seq.size()<<endl;
        for (ll g : seq) cout<<g<<' ';
        cout<<endl;
    }
}