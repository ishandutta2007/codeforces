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
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
#define ld long double
   
mt19937 rnd;
int rand(int a) { return (rnd() % a + a) % a; }
 
const int inf = 1e9 + 2;
const int max_n = 1e4 + 3, mod = 1e9 + 7;
 
 
int sum(int a, int b) { 
    int r = a + b;
    if (r >= mod) r -= mod;
    if (r < 0) r += mod;
    return r;
}
int mul(int a, int b) { return a * b % mod; }
int binpow(int a, int b) {
    int r = 1;
    for (; b; b /= 2, a = mul(a, a))
        if (b & 1) r = mul(r, a);
    return r;
}
 
int rev(int a) { return binpow(a, mod - 2); }
 
map<pii, int> number;
vector<vector<int>> A;
 
int r;
int range;
 
void gauss() {
    int need = number[mp(0, 0)];
    int cnt = 0;
 
    int n = size(A);
    for (int i = 0; i < n; ++i) {
        int num = rev(A[i][range]);
        for (auto& j : A[i])
            j = mul(j, num);

        for (int j = i + 1; j < min(n, i + 2 * r); ++j) {
            if (j == i || !A[j][i - j + range]) continue;
            int num = A[j][i - j + range];
            for (int k = max(0ll, j - range); k < min(n, range + i); ++k) {
                int t1 = k - i + range, t2 = k - j + range;
                ++cnt;
                A[j][t2] = sum(A[j][t2], -mul(A[i][t1], num));
            }
            A[j][2 * range] = sum(A[j][2 * range], -mul(A[i][2 * range], num));
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j > max(0ll, i - 2 * r); --j) {
            A[j][2 * range] = sum(A[j][2 * range], -mul(A[j][i - j + range], A[i][2 * range]));
            A[j][i - j + range] = 0;
        }
    }

    //cout << "cnt " << cnt << " " << binpow(r, 4) << endl;
}
 
void run() {
    int perc[4];
    int one;
    cin >> r >> perc[0] >> perc[1] >> perc[2] >> perc[3];
    one = accumulate(perc, perc + 4, 0);
    perc[0] = mul(perc[0], rev(one)), perc[1] = mul(perc[1], rev(one)), perc[2] = mul(perc[2], rev(one)), perc[3] = mul(perc[3], rev(one));
 
    for (int x = -r - 1; x <= r + 1; ++x)
        for (int y = -r - 1; y <= r + 1; ++y)
            if (x * x + y * y <= (r + 1) * (r + 1)) number[{x, y}] = size(number);
 
    int n = size(number);
    r = (2 * r + 1);
    range = 3 * r;

    A.resize(n, vector<int>(2 * range + 1));
 
    vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
    for (auto p : number) {
        int x = p.fi.fi, y = p.fi.se;
        ld id = p.se;
        A[id][range] = 1;
        A[id][2 * range] = 1;
        if (x * x + y * y > (r / 2) * (r / 2)) { A[id][2 * range] = 0; continue; }
 
        for (int dir = 0; dir < 4; ++dir) {
            pii tmp = {x + dx[dir], y + dy[dir]};
            if (number.count(tmp)) A[id][number[tmp] - id + range] = mod - perc[dir];
        }
    }
    
    gauss();
 
    cout << A[number[mp(0, 0)]][2 * range] << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(6);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    clock_t time = clock();
    int t = 1;
    //cin >> t;
    while(t--) run();

    //cout << ((double)clock() - time) / CLOCKS_PER_SEC << endl;
}