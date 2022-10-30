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

void run() {
    int n;
    cin >> n;
    int lst = 0;
    int xl = 1, xr = n;
    bool pref = true;

    int cnt = 0;
    while (xr-xl > 1) {
        int mid = (xr+xl)/2;
        // 0 k
        // 0 1 2)
        // n-k n-k+1 .. n-1
        // 
        int ad = n-mid;
        ++cnt;
        if (cnt > 10) {
            exit(1);
        }
        cout << "+ " << ad << endl;
        int r; cin >> r;

        if (r != lst) {
            xl = 0;
            xr = (xr-1 + ad) % n + 1;
            pref = !pref;
        } else {
            xl += ad;
            xr = n;
        }
        //cout << "d " << xr - xl << endl;
        lst = r;
    }
    cout << "! " << xl + n*lst << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}