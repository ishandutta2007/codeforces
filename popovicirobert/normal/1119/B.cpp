#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*
const int MOD = ;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}


inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}
*/

using namespace std;

int arr[3001];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif // ONPC
    int i, n, h, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> h;

    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for(i = 0; i < n; i++) {
        sort(arr, arr + i + 1);
        ll cur = 0;
        for(j = i; j >= 0; j -= 2) {
            cur += arr[j];
        }
        if(cur <= h) {
            ans = i + 1;
        }
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}