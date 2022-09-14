//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const ll inf=2e18;
const ll mod=998244353;
const ll mod1=mod*mod;
const int N=500010;
int a[N];
int b[N];
int mex(vector<int>v){
    sort(v.begin(),v.end());
    if (v.empty() || v[0]>0) return 0;
    for (int i=1;i<v.size();i++){
        if (v[i]>v[i-1]+1) return v[i-1]+1;
    }
    return v.back()+1;
}
int dp[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=1+(c=='B');
    }

    int A=0;
    int B=0;
    int xr=0;
    for (int i=1;i<=n;i++){
        int j=i;
        while (j<n && a[j+1]!=a[j]) j++;
        int cur=j-i+1;
        if (cur%2==0){
            xr^=dp[cur];
        } else {
            if (a[i]==1){
                xr^=dp[cur];
                A++;
            } else {
                xr^=dp[cur];
                B++;
            }
        }
        i=j;
    }
    A+=(xr>0);
    if (A>B) cout<<"Alice\n";
    else cout<<"Bob\n";
//    RBR00BRB
//12
//R
//RBRBRBR
//
//B
//




}
int32_t main() {
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for (int i=3;i<=200;i++){
        vector<int>v;
        for (int j=0;j<=i-2;j++){
            v.push_back(dp[j]^dp[i-2-j]);
        }
        dp[i]=mex(v);
//        cout<<dp[i]<<",";
    }
    for (int i=201;i<N;i++) dp[i]=dp[i-34];
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

//CRES
/**
12
RBRBRBRB

BR


**/