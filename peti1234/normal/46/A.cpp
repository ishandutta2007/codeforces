#include <bits/stdc++.h>

using namespace std;
int n, sum=1;
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        sum+=i, sum%=n;
        if (!sum) sum+=n;
        cout << sum << " ";
    }
    return 0;
}