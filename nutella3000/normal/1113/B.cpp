#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    long long sum = 0;
    sort(a,a + n);
    for(int i = 0;i < n;i++) {
        sum += a[i];
    }
    long long min = sum;
    for(int i = 1;i <= 100;i++) {
        long long sum1 = 0;
        for(int j = 0;j < n;j++) {
            if (min > sum + a[j] / i - a[j] + a[0] * (i - 1) && a[j] % i == 0) min = sum + a[j] / i + a[0] * (i - 1) - a[j];
        }
    }
    cout << min;
}