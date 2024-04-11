#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    n/=2;
    cout << (a<n || a>n+1 || b<n || b>n+1 ? "YES" : "NO") << "\n";
    return 0;
}