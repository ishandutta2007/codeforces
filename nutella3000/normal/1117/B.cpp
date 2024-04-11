#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int main() {
    cin.tie();
    cout.tie();
    cout.precision(20);
    int n,m,k;
    cin >> n >> m >> k;k++;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    long long ans = 0;
    sort(a,a + n);
    cout <<( (long long) (k - 1) * a[n - 1] + a[n - 2]) * (m / k) + (long long) (m % k) * a[n - 1];
}