#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

auto que(int l, int r) {
    cout << "? " << l << " " << r << endl;
    vector<int> arr(r-l+1);
    for (int i = 0; i < r-l+1; ++i)
        cin >> arr[i];
    return arr;
}

bool good(int l, int r) {
    auto a = que(l, r);
    int cnt = 0;
    for (int i : a) {
        if (i >= l && i <= r) ++cnt;
    }
    return !(cnt & 1);
}

void run() {
    int n; cin >> n;
    int l = 1, r = n;
    while (r - l >= 1) {
        int mid = (l + r)/2;
        if (good(l, mid)) l = mid+1;
        else r = mid;
    }
    cout << "! " << l << endl;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}