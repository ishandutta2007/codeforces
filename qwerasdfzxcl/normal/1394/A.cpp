#include <bits/stdc++.h>
#define int long long
#define ll long long

using namespace std;
int a[100100];

void solve(){
    int n, d, m;
    scanf("%lld %lld %lld", &n, &d, &m);
    vector<int> X, Y;
    for (int i=0;i<n;i++){
        scanf("%lld", a+i);
        if (a[i]>m) X.push_back(a[i]);
        else Y.push_back(a[i]);
    }
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end());
    vector<ll> S(Y.size());
    if (!Y.empty())S[0] = Y[0];
    for (int i=1;i<(int)Y.size();i++) S[i] = S[i-1]+Y[i];
    ll ans = 0, cur = 0;
    if (!Y.empty()) ans = S.back();
    for (int i=0;i<(int)X.size();i++){
        if ((ll)d*i+i+1>n) break;
        cur += X[i];
        ll tmp = 0;
        ll tmp2 = (ll)d*i - ((int)X.size()-i-1);
        if (tmp2<=0 && !Y.empty()) tmp = S.back();
        if (tmp2>0 && tmp2<(ll)Y.size()) tmp = S.back()-S[tmp2-1];
        ans = max(ans, cur+tmp);
    }
    printf("%lld\n", ans);
}

signed main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}