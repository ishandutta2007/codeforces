#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=200010;
ll a[N];
ll ANS=0ll;
void upd_ans(ll mask){
    if (__builtin_popcountll(mask)>__builtin_popcountll(ANS)) ANS=mask;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int dp[(1<<15)];
void solve(){
    int n,m,p;cin>>n>>m>>p;
    for (int i=1;i<=n;i++){
        for (int j=0;j<m;j++){
            char c;cin>>c;
            if (c=='1') a[i]^=(1ll<<j);
        }
    }
    for (int it=1;it<=40;it++){
        int r=rnd()%n+1;
        vector<int>v;
        for (int i=0;i<m;i++){
            if (a[r]&(1ll<<i)) v.push_back(i);
        }
        for (int mask=0;mask<(1<<v.size());mask++) dp[mask]=0;
        for (int i=1;i<=n;i++){
            int cur=0;
            for (int j=0;j<v.size();j++){
                if (a[i]&(1ll<<v[j])) cur^=(1<<j);
            }
            dp[cur]++;
        }
        for (int j=0;j<v.size();j++){
            for (int mask=0;mask<(1<<v.size());mask++){
                if (mask&(1<<j)){
                    dp[mask^(1<<j)]+=dp[mask];
                }
            }
        }
        for (int mask=0;mask<(1<<v.size());mask++){
            if (dp[mask]>=(n+1)/2){
                ll cur=0ll;
                for (int i=0;i<v.size();i++){
                    if (mask&(1<<i)) cur^=(1ll<<v[i]);
                }
                upd_ans(cur);
            }
        }
 
    }
    for (int i=0;i<m;i++){
        if (ANS&(1ll<<i)) cout<<1;
        else cout<<0;
 
    }
    cout<<endl;
 
 
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//x+y x-y
//
//
//x+y -2*y
//
//x-y
 
//x y
//x x-y
//x x-2*y