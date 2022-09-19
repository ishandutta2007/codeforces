#include <bits/stdc++.h>

using namespace std;
int n, sum, x;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) {
        cin >> x;
        if (i==j || i+j==n+1 || i-1==n/2 || j-1==n/2) sum+=x;
    }
    cout << sum << "\n";
    return 0;
}