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
    int a, b, k, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> b >> k;
    int ans = 0;
    for(i = k - 1; i >= 0; i--) {
        cin >> a;
        if(i == 0) {
            ans += a;
        }
        else {
            ans += a * b;
        }
        ans &= 1;
    }
    if(ans) {
        cout << "odd";
    }
    else {
        cout << "even";
    }
    //cin.close();
    //cout.close();
    return 0;
}