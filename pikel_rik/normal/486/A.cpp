#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int sum = floor(n/2);
    if (n % 2 != 0)
        sum -= n;
    cout << sum;
}