#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

int n;

inline int check(int val) {
    if(val <= 2)
        return 0;
    //printf("%d %d\n" ,val,max(0, min(val / 2, min(val - 2, n - 1)) - max(1, val - n) + 1));
    return max(0, min((val - 1) / 2, min(val - 2, n - 1)) - max(1, val - n) + 1);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n;
    ll p10 = 1, val = 0;
    while(val <= n + n - 1) {
        val = val * 10 + 9;
        p10 = p10 * 10;
    }
    val /= 10;
    p10 /= 10;
    int ans = 0;
    for(i = 0; i <= 9; i++) {
        if(1LL * i * p10 + val <= n + n - 1)
            ans += check(i * p10 + val);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}