#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int cnt[1101][5];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        string s;cin>>s;
        for (int j=0;j<m;j++){
            cnt[j+1][s[j]-'A']++;
        }
    }
    ll res=0ll;
    for (int i=1;i<=m;i++){
        int x;cin>>x;
        int maxx=0;
        for (int j=0;j<5;j++) maxx=max(maxx,cnt[i][j]);
        res+=maxx*x*1ll;
    }
    cout<<res;
    return 0;
}