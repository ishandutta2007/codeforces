#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    int k = 0;
    for(i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum += a;
        k = max(k, a);
    }
    while(1LL * k * n - sum <= sum) {
        k++;
    }
    cout << k;
    //cin.close();
    //cout.close();
    return 0;
}