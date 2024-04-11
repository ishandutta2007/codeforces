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
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = 2e5 + 3;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> ids((int)2e5);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ids[a[i]].pb(i);
    }
    int res = -1;
    for (int num = 0; num < 2e5; ++num) {
        for (int i = 0; i < size(ids[num])-1; ++i) {
            int v1 = ids[num][i], v2 = ids[num][i+1];
            chkmax(res, v1+(n-v2));
        }
    }
    cout << res << endl;
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
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}