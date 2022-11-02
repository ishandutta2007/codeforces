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

void run() {
    string s, t;
    cin >> s >> t;
    bool a = false;
    for (auto i : s)
        if (i == 'a') a = true;
    sort(all(s), [&](auto v1, auto v2) {
        if (t != "abc" || !a) return v1 < v2;
        if (v1 == 'c' && v2 == 'b') return true;
        if (v1 == 'b' && v2 == 'c') return false;
        return v1 < v2;
    });
    cout << s << endl;
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