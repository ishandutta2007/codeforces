#include <bits/stdc++.h>

using namespace std;
long long n, k, sum;
int main()
{
    cin >> n >> k;
    sum=-n;
    for (int i=1; i; i++) {
        sum+=i+1;
        if (sum==k) {
            cout << n-i << "\n";
            return 0;
        }
    }
    return 0;
}