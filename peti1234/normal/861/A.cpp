#include <bits/stdc++.h>

using namespace std;
long long n;
int k;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        if (n%2==0) {
            n/=2;
        }
        if (n%5==0) {
            n/=5;
        }
    }
    for (int i=1; i<=k; i++) {
        n*=10;
    }
    cout << n;
    return 0;
}