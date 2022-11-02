#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);
 
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> suf(n + 1);
    vector<ll> k(q);
 
    for(int i = 0;i < n;i++) cin >> a[i];
 
    reverse(all(a));
 
    for(int i = 0;i < q;i++) cin >> k[i];
 
    for(int i = n - 1;i >= 0;i--) {
        suf[i] = suf[i + 1] + a[i];
    }
 
    int s = n - 1;
    int hp = a[n - 1];
    for(int i = 0;i < q;i++) {
        int l = -1;
        int r = s + 1;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if (suf[mid] - suf[s] + hp <= k[i]) r = mid;
            else l = mid;
        }
        if (l == -1) {
            s = n - 1;
            hp = a[n - 1];
        }else {
            hp = suf[l] - suf[s] + hp - k[i];
            s = l;
        }
 
        cout << s + 1 << endl;
    }
}