#include <bits/stdc++.h>


using namespace std;



int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int n, b, p;
    cin >> n >> b >> p;
    int ans1 = 0, ans2 = n * p;
    while(n > 1) {
        int k = 1;
        while(k <= n)
            k <<= 1;
        k >>= 1;
        ans1 += k * b + k / 2;
        n = k / 2 + n - k;
    }
    cout << ans1 << " " << ans2;
    //cin.close();
    //cout.close();
    return 0;
}