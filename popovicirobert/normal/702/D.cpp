#include <bits/stdc++.h>


using namespace std;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    long long d, k, a, b, t;
    ios::sync_with_stdio(false);
    cin >> d >> k >> a >> b >> t;
    long long ans = a * min(d, k) + (d - min(d, k)) * b;
    for(long long i = 0; i <= min(d, k); i++) {
        long long x = (d - i - 1) / k;
        ans = min(ans, i * b + a * (d - i) + x * t);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}