#include "bits/stdc++.h"
using namespace std;
long long n , m;
int main(){
    cin >> n >> m;
    long long x = n / m;
    long long ans1 = x * (x - 1) / 2;
    ans1 *= (m - (n % m));
    ans1 += (x * (x + 1) / 2) * (n % m);
    long long ans2 = (n - m + 1) * (n - m) / 2;
    cout << ans1 << " " << ans2;
}