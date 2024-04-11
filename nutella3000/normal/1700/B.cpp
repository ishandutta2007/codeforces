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

void run() {
    int n; string s; cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = s[i] - '0';


    a[n-1] -= 1;

    vector<int> b(n);

    for (int i = n-1; i >= 0; --i) {
        b[i] = -a[i];
        if (b[i] < 0) {
            b[i] += 10;
            if (i) a[i-1] += 1;
        }
    }

    if (b[0] == 0) {
        for (int i = 0; i < n; ++i)
            a[i] = s[i] - '0';
        a[n-1] -= 1;

        a[n-2] -= 1;
        a[0] -= 1;
        
        for (int i = n-1; i >= 0; --i) {
            b[i] = -a[i];
            if (b[i] < 0) {
                b[i] += 10;
                if (i) a[i-1] += 1;
            }
        }
    }

    for (auto i : b)
        cout << i;
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}