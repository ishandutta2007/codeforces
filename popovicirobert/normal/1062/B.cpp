#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e6;

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int n, i, j;
    ios::sync_with_stdio(false);
    cin >> n;
    vector <int> expo;
    int val = 1;
    int d = 2;
    int mx = 0;
    while(d * d <= n) {
        int cnt = 0;
        while(n % d == 0) {
            n /= d;
            cnt++;
        }
        if(cnt) {
            val *= d;
            expo.push_back(cnt);
        }
        mx = max(mx, cnt);
        d++;
    }
    if(n > 1) {
        mx = max(mx, 1);
        val *= n;
        expo.push_back(1);
    }
    int bit = 0;
    while((1 << bit) < mx) {
        bit++;
    }
    bool flag = 0;
    for(auto it : expo) {
        if(it != (1 << bit)) {
            flag = 1;
        }
    }
    cout << val << " " << flag + bit;
    //cin.close();
    //cout.close();
    return 0;
}