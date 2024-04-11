#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
//const int max_n = 4e5 + 3;

void run() {
    int n;
    cin >> n;
    string s = "";
    if (n % 2 == 1) s += 'c', --n;
    if (n) {
        for (int i = 0; i < n / 2; ++i)
            s += 'a';
        s += 'b';
        for (int i = 0; i < n / 2 - 1; ++i)
            s += 'a';
    }
    
    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

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