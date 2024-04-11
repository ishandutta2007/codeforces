#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2>
void sMin(T1 &a, T2 b) {
    a = min(a, (T1) b);
}
template<class T1, class T2>
void sMax(T1 &a, T2 b) {
    a = max(a, (T1) b);
}

#define int long long
typedef long long ll;
#define size(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

template<class IT>
void print(IT b, IT e, string sep=" ", string en="\n") {
    while (b != e) {
        cout << *(b++) << sep;
    }
    cout << en;
}

bool run();

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(15);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        if (!run()) cout << "NO" << endl;
    }
}

const int inf = 1e9 + 7;

bool run() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) 
        cin >> s[i];

    int t = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0;j < m; ++j) {
            int num = -1;
            if (s[i][j] == 'R') {
                num = (i + j) % 2;
            }else if (s[i][j] == 'W') num = (i + j + 1) % 2;
            if (s[i][j] == '.') continue;
            if (t != -1 && t != num) return false;
            t = num;
        }
    }
    if (t == -1) t = 0;

    cout << "YES" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0;j < m; ++j) {
            if ((i + j) % 2 == t) cout << 'R';
            else cout << 'W';
        }
        cout << endl;
    }
    return true;
}