#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = -(ll)4e18;
    ll S = 0;
    for(auto x : a) S += x;
    ll fix = a[n - 1] * 1ll * (S - a[n - 1]);
    ll oo = (n - 1) * 1ll * a[n - 1] + (S - a[n - 1]);
    if(oo < 0){
        cout << "INF\n";
        return;
    }
    res = max(res, fix - oo * a[n - 1]);
    fix = a[0] * 1ll * (S - a[0]);
    oo = (n - 1) * 1ll * a[0] + (S - a[0]);
    if(oo > 0){
        cout << "INF\n";
        return;
    }
    res = max(res, fix - oo * a[0]);
    ll P = 0, Q;
    ll p1, p2;
    for(int i = 0 ; i + 1 < n; i ++ ){
        P += a[i];
        Q = S - P;
        p1 = -a[i];
        p2 = -a[i+1];
        res = max(res, (a[n - 1] + p1) * 1ll * (P + (i + 1) * 1ll * p1) + (a[0] + p1) * 1ll * (Q + (n - i - 1) * 1ll * p1) - (a[0] + p1) * 1ll * (a[n - 1] + p1) - (n - 1) * 1ll * p1 * p1);
        res = max(res, (a[n - 1] + p2) * 1ll * (P + (i + 1) * 1ll * p2) + (a[0] + p2) * 1ll * (Q + (n - i - 1) * 1ll * p2) - (a[0] + p2) * 1ll * (a[n - 1] + p2) - (n - 1) * 1ll * p2 * p2);
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}