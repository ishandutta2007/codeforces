#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, p=1;
    cin >> n >> k;
    if (k==1) cout << n << "\n";
    else {
        while(p<=n) p*=2;
        cout << p-1 << "\n";
    }
    return 0;
}