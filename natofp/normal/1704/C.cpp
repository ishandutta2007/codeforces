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
#define mt make_tuple

using namespace std;

int n, m;

void solve(){
    cin >> n >> m;
    vector<int> a;
    for(int i=1;i<=m;i++){
        int x; cin >> x;
        a.pb(x);
    }
    if(a.size() == 1){
        cout << 2 << "\n";
        return;
    }
    sort(a.begin(), a.end());
    vector<int> sz;
    for(int i=1;i<m;i++) sz.pb(a[i] - a[i - 1] - 1);
    sz.pb(n - (a.back() - a[0] + 1));
    sort(sz.begin(), sz.end());
    reverse(sz.begin(), sz.end());
    int ans = 0;
    for(int i=0;i<m;i++){
        int bylo_rund = i * 2;
        int rest = sz[i] - bylo_rund * 2;
        if(rest > 0) ans += max(1, rest - 1);
    }
    cout << n - ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}