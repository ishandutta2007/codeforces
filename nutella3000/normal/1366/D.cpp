#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = 1e7 + 1;

int d1[max_n], d2[max_n], d[max_n];

void solve() {
    for(int i = 2;i < max_n;i++) {
        if (d[i] == 0) {
            for(int j = i * i;j < max_n;j += i)
                if (d[j] == 0) d[j] = i;
        }
        d1[i] = d2[i] = -1;
        int p1, p2;

        if (d[i] == 0) continue;
        int v = i;
        p1 = d[i];
        while(v % d[i] == 0) v /= d[i];

        if (v == 1) continue;

        p2 = d[v];
        if (d[v] == 0) p2 = v;

        if (p1 == 2) p2 = v;
        
        d1[i] = p1;
        d2[i] = p2;
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0;i < n;i++)
        cout << d1[a[i]] << " ";
    cout << endl;
    for(int i = 0;i < n;i++) 
        cout << d2[a[i]] << " ";
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}