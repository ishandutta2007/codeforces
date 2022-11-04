#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> arr1, arr2;
    vector <int> a(n + 1), b(n + 1);

    for(i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] < b[i]) {
            arr1.push_back(i);
        }
        else {
            arr2.push_back(i);
        }
    }

    sort(arr1.begin(), arr1.end(), [&](const int &x, const int &y) {
                return b[x] > b[y];

         });

    sort(arr2.begin(), arr2.end(), [&](const int &x, const int &y) {
                return b[x] < b[y];

         });

    if(arr1.size() < arr2.size()) {
        swap(arr1, arr2);
    }

    cout << arr1.size() << "\n";
    for(auto it : arr1) {
        cout << it << " ";
    }

    return 0;
}