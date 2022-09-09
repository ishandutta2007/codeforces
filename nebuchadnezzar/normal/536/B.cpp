#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 1e6 + 5;
const LL MOD = 1e9 + 7;

int n, m;
string s;
int inp[MAXN];
int zf[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    cin >> s;

    int nl = 0, nr = 0;
    for (int i = 1; i < szof(s); ++i) {
        int start = 0;
        if (nr > i) {
            start = min(nr - i + 1, zf[i - nl]);
        }
        for (; start + i < szof(s) && s[start] == s[start + i]; ++start);
        zf[i] = start;
        if (i + start - 1 > nr) {
            nl = i;
            nr = i + start - 1;
        }
    }

    /*
    for (int i = 0; i < szof(s); ++i) {
        cout << zf[i] << " ";
    }
    cout << endl;
    */

    vector <int> v;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        inp[num - 1] = 1;
        v.puba(num - 1);
    }

    sort(bend(v));

    for (int i = 1; i < szof(v); ++i) {
        if (v[i] - v[i - 1] < szof(s) && zf[v[i] - v[i - 1]] != szof(s) - (v[i] - v[i - 1])) {
            cout << 0 << endl;
            return 0;
        }
    }

    int now = -1e9;
    LL ans = 1;
    for (int i = 0; i < n; ++i) {
        if (inp[i]) {
            now = i;
        }
        if (i - now < szof(s)) {
            
        } else {
            ans = (ans * 26) % MOD;
        }
    }

    cout << ans << endl; 

    return 0;
}