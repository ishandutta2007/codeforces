#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

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
}*/


using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector <int> t(m + 1), l(m + 1), r(m + 1);
    vector <bool> small(n + 1), big(m + 1);

    for(i = 1; i <= m; i++) {
        cin >> t[i] >> l[i] >> r[i];
        if(t[i] == 1) {
            for(j = l[i]; j < r[i]; j++) {
                small[j] = 1;
            }
        }
    }

    for(i = 1; i <= m; i++) {
        if(t[i] == 0) {
            int cnt = 0;
            for(j = l[i]; j < r[i]; j++) {
                if(small[j] == 0) {
                    big[j] = 1;
                    cnt++;
                }
            }
            if(cnt == 0) {
                cout << "NO";
                return 0;
            }
        }
    }

    vector <int> arr(n + 1);
    arr[1] = 2000;

    cout << "YES\n" << arr[1] << " ";
    for(i = 1; i < n; i++) {
        if(small[i]) {
           arr[i + 1] = arr[i];
        }
        else {
            arr[i + 1] = arr[i] - 1;
        }
        cout << arr[i + 1] << " ";
    }

    //cin.close();
    //cout.close();
    return 0;
}