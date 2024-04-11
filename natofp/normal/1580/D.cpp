#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 4005;
int n, m;
ll a[nax];

vector<ll> reku(int L, int R){
    if(L > R) return {0};
    if(L == R){
        return {0, a[L] * (m - 1)};
    }
    int pos = L;
    ll v = a[L];
    for(int i=L;i<=R;i++){
        if(a[i] < v){
            v = a[i];
            pos = i;
        }
    }
    auto LF = reku(L, pos - 1);
    auto RG = reku(pos + 1, R);
    vector<ll> ans(R-L+2, -2e18);
    for(int i=0;i<LF.size();i++){
        for(int j=0;j<RG.size();j++){
            ans[i + j] = max(ans[i + j], LF[i] + RG[j] - v * i * j * 2);
            ans[i + j + 1] = max(ans[i + j + 1], LF[i] + RG[j] + v * m - v * i * j * 2 - v - v * (i + j) * 2);
        }
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    auto res = reku(1, n);
    cout << res[m] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}