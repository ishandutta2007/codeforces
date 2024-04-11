#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }



mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7, mod = 998244353;
const int N = (1 << 18);

int n;
int a[N];
int cnt[N], all[N];

void run() {
    cin >> n;
    for (int i = 0; i <= n; ++i)
        cnt[i] = all[i] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++all[a[i]];
    }
    vector<int> b;
    int id = 0, lst = 0;
    while (id < n) {
        for (int i = lst; i < id; ++i) {
            --cnt[a[i]]; --all[a[i]];
        }
        lst = id;

        int t = 0;
        for (; id < n; ++id) {
            if (all[t] == 0) break;
            ++cnt[a[id]];
            while (cnt[t]) ++t;
        }
        b.pb(t);
        if (t == 0) ++id;
    }
    cout << size(b) << endl;
    for (auto i : b)
        cout << i << " ";
    cout << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}