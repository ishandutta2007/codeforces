#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;
 
int n, k;
vector<int> a;

bool have(int l, int r, int cnt, int Max) {
    bool last = false;
    for(int i = l;i <= r;i++) {
        if (a[i] <= Max && !last) {
            last = true;
            cnt--;
        }
        else last = false;
    }
    return cnt <= 0;
}

int f(int l, int r, int cnt) {
    int left = -1;
    int right = 1e9 + 1;
    while(right - left > 1) {
        int mid = (left + right) / 2;
        if (have(l, r, cnt, mid)) right = mid;
        else left = mid;
    }
    return right;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    int res = 0;
    if (k % 2 == 0) res = min(f(0, n - 2, (k + 1) / 2), f(1, n - 1, k / 2));
    if (k % 2 == 1) res = min(f(0, n - 1, (k + 1) / 2), f(1, n - 2, k / 2));
    cout << res << endl;
}

 
 
signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    solve();
}