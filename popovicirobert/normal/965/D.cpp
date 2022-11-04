#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

ll a[MAXN + 1];
int l, w;

inline bool check(int nr) {
    int mx = 0;
    int pos = 0;
    for(int i = 1; i <= w; i++) {
        while(a[pos] < a[i - 1] + 1 - nr) {
            pos++;
        }
        if(a[i - 1] + 1 - nr <= a[pos])
            mx = max(mx, i - pos);
    }
    return mx <= l;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> w >> l;
    for(i = 1; i < w; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    a[w] = a[w - 1] + 1;
    int res = 0;
    for(int step = 1 << 30; step; step >>= 1) {
        if(check(res + step))
            res += step;
    }
    cout << res;
    //cin.close();
    //cout.close();
    return 0;
}