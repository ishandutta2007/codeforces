#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int a, b, c, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    int ans = 0;
    for(i = 0; i <= a; i++) {
        if(i + 1 <= b && i + 2 <= c) {
            ans = i + i + 1 + i + 2;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}