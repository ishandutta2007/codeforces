//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=2000010;
const ll mod=1000000007ll;
int cnt[33];
ll pw2[N];
void solve(){
    int n;cin>>n;
    pw2[0]=1;
    for (int i=1;i<=n;i++){
        pw2[i]=(pw2[i-1]*2)%mod;
        int x;cin>>x;
        int cur=0;
        while (x%2==0) x/=2,cur++;
        cnt[cur]++;
    }
    ll res=(pw2[cnt[0]]-1ll)*(pw2[n-cnt[0]])%mod;
    for (int i=1;i<30;i++){
        if (cnt[i]<=1) continue;
        ll cur=(pw2[cnt[i]-1]-1);
        for (int j=i+1;j<30;j++){
            cur*=pw2[cnt[j]];
            cur%=mod;
        }
        res+=cur;
        res%=mod;
    }
    cout<<res<<endl;

}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
**/