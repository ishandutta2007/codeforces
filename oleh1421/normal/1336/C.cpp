//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=3010;
const int mod=998244353ll;
int dp[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    s='.'+s;
    t='.'+t;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=n+1;j++){
            dp[i][j]=(i>j);
        }
    }
    for (int len=1;len<=n;len++){
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=0;
            if (l>m || s[len]==t[l]){
                dp[l][r]+=dp[l+1][r];
            }
            if (r>m || s[len]==t[r]){
                dp[l][r]+=dp[l][r-1];
            }
            dp[l][r]%=mod;
        }
    }
    int res=0;
    for (int i=m;i<=n;i++){
        res+=dp[1][i];
        res%=mod;
    }
    cout<<res;
    return 0;
}

/*
2 2
0 1
10 1
*/