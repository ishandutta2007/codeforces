#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

double prob[MAXN + 1];

inline double lgput(double a, int b) {
    double ans = 1.0;
    while(b > 0) {
        if(b & 1)
            ans = 1.0 * ans * a;
        b >>= 1;
        a = 1.0 * a * a;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> m >> n;
    //n++;
    for(i = 1; i <= m; i++) {
        prob[i] = lgput(1.0 * i / m, n);
    }
    double ans = 0;
    for(i = m; i >= 1; i--) {
        ans += 1.0 * i * (prob[i] - prob[i - 1]);
    }
    cout << fixed << setprecision(20) << ans;
    //cin.close();
    //cout.close();
    return 0;
}