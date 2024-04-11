#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    long long ans = 0, a, b;
    cin >> a >> b;
    while(a && b) {
        if(a > b) {
            ans += a / b;
            a %= b;
        } else {
            ans += b / a;
            b %= a;
        }
    }
    cout << ans;
    return 0;
}