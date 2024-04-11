#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 3e5;

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, x, y, i;
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    cin >> str + 1;
    str[0] = '1';
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(str[i] == '0' && str[i - 1] == '1') {
            cnt++;
        }
    }
    if(cnt == 0) {
        cout << 0;
        return 0;
    }
    if(x > y) {
        cout << 1LL * cnt * y;
    }
    else {
        cout << 1LL * (cnt - 1) * x + y;
    }
    //cin.close();
    //cout.close();
    return 0;
}