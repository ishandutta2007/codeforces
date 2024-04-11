#include <bits/stdc++.h>
using namespace std;
     
//#define _GLIBCXX_DEBUG
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
int rand(int a) { return (rnd() % a + a) % a; }
 
const int inf = 1e15 + 2;
const int mod = 998244353;

int binpow(int a, int b) {
    int r = 1;
    for (; b; b /= 2, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}

int rev(int a) { return binpow(a, mod - 2); }

int Cnk(int n, int k) {
    int r = 1;
    for (int i = 1; i <= n; ++i) {
        r = r * i % mod;
        if (i <= k) r = r * rev(i) % mod;
        if (i <= n - k) r = r * rev(i) % mod;
    }
    return r;
} 

void run() {
    int n;
    string s;
    cin >> n >> s;
    int c1 = 0, c2 = 0;
    int lst = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++c2;
        if (i && s[i] == '1' && s[i - 1] == '1' && !lst) ++c1, lst = true;
        else lst = false; 
    }
    cout << Cnk(c1 + c2, c1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
     
    clock_t time = clock();

    int t = 1;
    cin >> t;
    while(t--) {
        run();
    }
}