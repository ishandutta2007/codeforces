#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int fr[101];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, r, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> r;
        for(j = 1; j <= r; j++) {
            cin >> x;
            fr[x]++;
        }
    }
    for(i = 1; i <= 100; i++) {
        if(fr[i] == n) {
            cout << i << " ";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}