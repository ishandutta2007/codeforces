#include <bits/stdc++.h>

using namespace std;
long long n, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    if (y<n || (y-n+1)*(y-n+1)+n-1<x) cout << -1;
    else {
        cout << y-n+1 << " ";
        for (int i=1; i<n; i++) cout << 1 << " ";
    }
    return 0;
}