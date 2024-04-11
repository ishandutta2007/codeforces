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

const int inf = 1e18 + 7, mod = 1e9 + 7;
const int N = 1504;

void run() {
    int n;
    cin >> n;
    vector<int> k(n), h(n);
    for (int i = 0; i < n; ++i)
        cin >> k[i];
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    int res = 0;
    int lst = 0, mh = 0;
    for (int i = 0; i < n; ++i) {
        int mn = inf;
        for (int j = i; j < n; ++j) {
            chmin(mn, k[j]-h[j]+1);
        }
        if (mn > lst) {
            // mn, mn+1, ... k[i]
            mh = k[i]-mn+1;
            res += mh*(mh+1)/2;
        } else {
            res += mh*(k[i]-lst)+(k[i]-lst)*(k[i]-lst+1)/2;
            mh += k[i]-lst;
        }
        lst = k[i];
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