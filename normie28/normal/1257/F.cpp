
// Problem : E. Knapsack
// Contest : Codeforces - Educational Codeforces Round 61 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1132/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
const int maxn = 110;
int a[maxn];
int main()
{
    fio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<vector<int>,int> mp;
    vector<int> v1,v2;
    int m=1<<15;
    for(int i=1;i<=n;i++){
        v1.push_back(a[i]/m);
        v2.push_back(a[i]%m);
    }
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            int tmp=v1[j]^i;
            v.push_back(__builtin_popcount(tmp));
        }
        mp[v]=i;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<30;j++){
            vector<int> v3;
            for(int k=0;k<n;k++){
                v3.push_back(j-__builtin_popcount(v2[k]^i));
            }
            if(mp.find(v3)!=mp.end()){
                cout<<((mp[v3]<<15)+i)<<endl; return 0;
            }
        }
    }
    cout<<-1;
}