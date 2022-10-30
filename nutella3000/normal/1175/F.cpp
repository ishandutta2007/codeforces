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
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 500;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> prv(n, -1), nxt(n, n);
    
    vector<int> past(n+1, -1);
    for (int i = 0; i < n; ++i) {
        prv[i] = past[a[i]];
        past[a[i]] = i;
    }
    fill(all(past), n);
    for (int i = n-1; i >= 0; --i) {
        nxt[i] = past[a[i]];
        past[a[i]] = i;
    }

    int res = 0;
    vector<int> mx_num(n, 1);
    for (int one = 0; one < n; ++one) {
        if (a[one] != 1) continue;
        ++res;

        int L = one, R = one+1, r_mx = 1;

        while (L && nxt[L-1] > one) {
            --L;
            mx_num[L] = max(mx_num[L+1], a[L]);
        }
        while (R < n && prv[R] < one) {
            chmax(r_mx, a[R]);
            chmax(L, prv[R]+1);
            if (L <= R+1-r_mx && mx_num[R+1-r_mx] <= r_mx) ++res;
            ++R;
        }

        L = one-1, R = one; int l_mx = 1;
        while (R+1 < n && prv[R+1] < one) {
            ++R;
            mx_num[R] = max(mx_num[R-1], a[R]);
        }
        while (L >= 0 && nxt[L] > one) {
            chmax(l_mx, a[L]);
            chmin(R, nxt[L]-1);
            if (R >= L+l_mx-1 && mx_num[L+l_mx-1] <= l_mx) ++res;
            --L;
        }
    }
    cout << res;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}