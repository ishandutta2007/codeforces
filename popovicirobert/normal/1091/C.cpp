#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

vector <ll> vals;

inline void solve(int d, int n) {
    int x = n / d;
    vals.push_back(x + 1LL * x * (x - 1) * d / 2);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            solve(i, n);
            if(i * i < n) {
                solve(n / i, n);
            }
        }
    }
    sort(vals.begin(), vals.end());
    for(auto it : vals) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}