#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=100010;
ll dp[N];
ll pref[N];
void solve(){
    ll n,k;cin>>n>>k;
    dp[0]=1ll;
    dp[1]=1ll;
    pref[0]=1ll;
    pref[1]=2ll;
    for (int i=2;i<=n;i++){
        dp[i]=pref[i-1];
        pref[i]=min(pref[i-1]+dp[i],k+1ll);
    }
    if (k>dp[n]){
        cout<<-1<<endl;
        return;
    }
    vector<int>ans;
    int i=1;
    while (i<=n){
        int j=i;
        while (k>dp[n-j]){
            k-=dp[n-j];
            j++;
        }
        for (int t=j;t>=i;t--){
            ans.push_back(t);
        }
        i=j+1;
    }
    for (int i:ans) cout<<i<<" ";
    cout<<endl;

}

int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3
//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/