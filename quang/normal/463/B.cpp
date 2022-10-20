#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

int n;
int h[N];

int main() {
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    h[0] = 0;
    long long e = 0, res = 0;
    for(int i = 1; i <= n; i++) {
        int a = h[i] - h[i - 1];
        if(a > 0) {
            if(e < a) {
                res += 1ll * (a - e);
                e = 0;
            }
            else
                e -= a;
        }
        else e -= a;
    }
    cout << res;
    return 0;
}