#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

vector<int> v[MAXN];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++)v[i].clear();
    ll a[n], w[k];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < k; i++){
        cin >> w[i];
    }
    sort(w, w+k);
    sort(a, a+n);
    for(int i = 0; i < k/2; i++)swap(w[i], w[k-i-1]);
    int po = 0;
    for(int i = 0; i < n-k; i++){
        while(w[po] == v[po].size()+1)po++;
        v[po].push_back(a[i]);
    }
    ll ans = 0;
    int qf = 1;
    for(int i = 0; i < k; i++){
        ans += a[n-i-1];
        if(v[i].size())ans += v[i][0];
        else ans += a[n-qf], qf++;
    }
    cout << ans << '\n';
}
int main(){
    int t=1;cin >> t;
    while (t--) solve();
}