#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;

    auto v = [&](int i){
        if (i <= 0 || i >= n-1) return false;
        return (a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1]);
    };

    int ans=0, cur=0;
    for (int i = 1; i < n-1; i++) if (v(i)) cur++;
    ans = cur;
    vector<int> x; x.reserve(6);
    for (int i = 0; i < n; i++){
        x.clear();
        x.push_back(0);
        x.push_back(1e9+10);
        if (i) x.push_back(a[i-1]), x.push_back(a[i-1]+1), x.push_back(a[i-1]-1);
        if (i<n-1) x.push_back(a[i+1]), x.push_back(a[i+1]+1), x.push_back(a[i+1]-1);

        int o = v(i-1)+v(i)+v(i+1), old = a[i];


        for (auto& it : x){
            a[i] = it;
            ans = min(ans, cur-o+v(i-1)+v(i)+v(i+1));
        }
        a[i] = old;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}