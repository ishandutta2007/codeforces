#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
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
 
    int n, m, X;
    cin >> n >> m >> X;
    vector<vector<int>> second_hand(n, vector<int>(m, 2));
    vector<string> a(n);
 
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
 
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int x = 0;x < n;x++) {
                for(int y = 0;y < m;y++) {
                    if (a[i][j] == 'S') continue;
                    if (a[x][y] != 'S') continue;
                    second_hand[i][j] = min(1ll, second_hand[i][j]);
                    if (hypot(x - i, y - j) - X > 1e-9) continue;
                    second_hand[i][j] = 0;
                }
            }
        }
    }
 
    int q;
    string s;
    cin >> q >> s;
    int res = 0;
    for(char c : s) {
        bool big = c < 'a';
        c = tolower(c);
 
        int Min = 2;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if (a[i][j] != c) continue;
                if (big) Min = min(Min, second_hand[i][j]);
                else Min = 0;
            }
        }
 
        if (Min == 2) res = inf;
        res += Min;
    }
 
    if (res >= inf) cout << -1;
    else cout << res;
}