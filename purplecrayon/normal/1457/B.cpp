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
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& it : a) cin >> it;
    int ans=1e9;
    vector<int> na(n);
    for (int c = 1; c <= 100; c++){
        int cv=0;
        for (int i = 0; i < n; i++) na[i] = a[i]!=c;
        for (int i = 0; i < n; i++) if (na[i]){
            cv++;
            for (int j = i; j < i+k; j++) na[i]=0;
            i += k-1;
        }
        ans = min(ans, cv);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}