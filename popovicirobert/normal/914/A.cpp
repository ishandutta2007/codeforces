#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 43

using namespace std;

const int INF = (int) 1e9;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int mx = -INF;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(x < 0)
            mx = max(mx, x);
        else {
            int a = sqrt(x);
            if(a * a != x)
                mx = max(mx, x);
        }
    }
    cout << mx;
    //cin.close();
    //cout.close();
    return 0;
}