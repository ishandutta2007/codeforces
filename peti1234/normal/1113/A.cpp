#include <bits/stdc++.h>

using namespace std;
int n, k, sum;
int main()
{
    cin >> n >> k;
    sum=min(n-1, k);
    for (int i=2; i<=n; i++) {
        if (i+k<=n) sum+=i;
    }
    cout << sum << "\n";
    return 0;
}