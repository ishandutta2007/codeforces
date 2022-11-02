#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7, mod = 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> b(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int st = 1, res = 0;
    for (int i = 0; i < n; ++i) {
        while (b[st]) ++st;
        if (a[i] <= n && !b[a[i]]) b[a[i]] = true;
        else {
            ++res;
            if (a[i] <= 2 * st) {
                cout << -1 << endl;
                return;
            }
            ++st;
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}