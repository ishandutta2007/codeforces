#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline bool check(int res, vector <int> &arr, int z) {
    int n = (int) arr.size() - 1;

    if(res * 2 > n) {
        return 0;
    }

    for(int i = 1; i <= res; i++) {
        if(arr[n - res + i] - arr[i] < z) {
            return 0;
        }
    }


    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, z;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> z;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(next(arr.begin()), arr.end());

    int res = 0;
    for(int step = 1 << 17; step; step >>= 1) {
        if(check(res + step, arr, z)) {
            res += step;
        }
    }

    cout << res;

    //cin.close();
    //cout.close();
    return 0;
}