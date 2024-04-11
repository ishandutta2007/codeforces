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

const int inf = 1e9 + 7;

void run() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    string s; cin >> s;
    vector<bool> used(n+1);
    vector<int> q(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == '0') ++cnt;

    int id1 = 1, id2 = cnt+1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (p[i] <= cnt) q[i] = p[i], used[p[i]] = true;
        } else if (p[i] > cnt) q[i] = p[i], used[p[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        while (used[id1]) ++id1;
        while (used[id2]) ++id2;

        if (s[i] == '0') {
            if (p[i] <= cnt) continue;
            q[i] = id1, used[id1] = true;
        } else {
            if (p[i] > cnt) continue;
            q[i] = id2, used[id2] = true;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << q[i] << " ";
    cout << endl;
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