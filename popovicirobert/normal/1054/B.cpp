#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int mx = -1;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(x > mx + 1) {
            cout << i;
            return 0;
        }
        mx = max(mx, x);
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}