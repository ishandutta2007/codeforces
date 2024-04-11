#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 300010;

int n, x;
int Gcd[N][20], Rmq[N][20];
vector <int> res;

bool Check(int l, bool flag) {
    int logl = (int)log2(l);
    bool ok = 0;
    for(int i = 1; i <= n - l + 1; i++) {
        int G = __gcd(Gcd[i][logl], Gcd[i + l - (1 << logl)][logl]);
        int M = min(Rmq[i][logl], Rmq[i + l - (1 << logl)][logl]);
        if(G == M) {
            ok = 1;
            if(flag) res.push_back(i);
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x, Gcd[i][0] = x, Rmq[i][0] = x;

    for(int i = 1; i <= (int)log2(n); i++)
    for(int j = 1; j <= n - (1 << i) + 1; j++) {
        Gcd[j][i] = __gcd(Gcd[j][i - 1], Gcd[j + (1 << (i - 1))][i - 1]);
        Rmq[j][i] = min(Rmq[j][i - 1], Rmq[j + (1 << (i - 1))][i - 1]);
    }
    int l = 1, r = n + 1;
    while(r - l > 1) {
        int m = (r + l) >> 1;
        if(Check(m, 0)) l = m;
        else r = m;
    }
    Check(l, 1);
    cout << res.size() << " " << l - 1 << endl;
    for(int i = 0 ; i < (int)res.size(); i++) cout << res[i] << " ";
    return 0;
}