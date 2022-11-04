#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline int getx(char ch) {
    if(ch == 'L') {
        return -1;
    }
    if(ch == 'R') {
        return 1;
    }
    return 0;
}

inline int gety(char ch) {
    if(ch == 'D') {
        return -1;
    }
    if(ch == 'U') {
        return 1;
    }
    return 0;
}

const int MAXN = (int) 2e5;

int sx[MAXN + 1], sy[MAXN + 1];
int x, y, n;

inline bool check(int len) {
    if(len > n) {
        return 1;
    }
    bool ans = 0;
    for(int i = 1; i + len - 1 <= n; i++) {
        int dx = sx[i - 1] + sx[n] - sx[i + len - 1], dy = sy[i - 1] + sy[n] - sy[i + len - 1];
        if((abs(dx - x) + abs(dy - y)) % 2 == len % 2 && abs(dx - x) + abs(dy - y) <= len) {
            ans = 1;
        }
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    for(i = 1; i <= n; i++) {
        sx[i] = sx[i - 1] + getx(str[i]);
        sy[i] = sy[i - 1] + gety(str[i]);
    }
    cin >> x >> y;
    int res = -1;
    for(int step = 1 << 17; step; step >>= 1) {
        if(!check(res + step)) {
            res += step;
        }
    }
    res++;
    if(res == n + 1) {
        cout << -1;
    }
    else {
        cout << res;
    }
    //cin.close();
    //cout.close();
    return 0;
}