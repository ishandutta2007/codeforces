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

void run();

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
        run();
    }
}

const int inf = 1e9 + 7;

void run() {
    int n;
    cin >> n;
    vector<int> a(n + 2);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            res += a[i] - max(a[i - 1], a[i + 1]);
            a[i] = max(a[i - 1], a[i + 1]);
        }
        res += abs(a[i] - a[i - 1]);
    }
    res += a[n];

    cout << res << endl;
}