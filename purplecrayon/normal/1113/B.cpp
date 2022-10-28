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

int pre[101][101];
bool has[101];

void solve(){
    int n; cin >> n; memset(has, 0, sizeof(has));
    vector<int> a(n); for (auto& it : a) cin >> it, has[it]=1;
    for (int i=1; i<=100; i++) for (int j=1; j<=100; j++) pre[i][j]=i+j;
    for (int g=1; g<=100; g++) for (int i=g; i<=100; i+=g) for (int j=1; j <=100; j++){
        pre[i][j] = min({pre[i][j], i/g+j*g});
    }
    int sm=accumulate(a.begin(), a.end(), 0), ans=sm;
    for (int i=1; i<=100; i++) for (int j=1; j<=100; j++) if (has[i]&&has[j]) ans = min(ans, sm-i-j+pre[i][j]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}