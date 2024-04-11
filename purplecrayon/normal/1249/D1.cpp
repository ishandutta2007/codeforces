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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, k;
ar<int, 3> a[MAXN];

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1], a[i][2] = i;

    sort(a, a+n, [&](ar<int, 3> i, ar<int, 3> j){ return i[1] > j[1]; });

    vector<bool> dead(n);

    const int MAX = 210;
    int ans=0;
    while (1) {
        int bad=-1, tot=-1;
        for (int i = 0; i < MAX; i++) {
            int cur=0;
            for (int j = 0; j < n; j++) if (!dead[j] && a[j][0] <= i && i <= a[j][1]) cur++;
            if (cur > k) { bad=i, tot=cur; break; }
        }
        if (bad==-1){ break; }

        ans += tot-k;

        vector<int> er;
        for (int j = 0; j < n; j++) if (!dead[j] && a[j][0] <= bad && bad <= a[j][1]) er.push_back(j);
        for (int i = 0; i < tot-k; i++) {
            dead[er[i]] = 1;
        }
    }
    cout << ans << '\n';
    vector<bool> pr(n);
    for (int i = 0; i < n; i++) if (dead[i]) pr[a[i][2]] = 1;
    for (int i = 0; i < n; i++) if (pr[i]) cout << i+1 << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}