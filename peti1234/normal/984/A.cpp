#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t[1005];
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    cout << (t[(n+1)/2]) << endl;
    return 0;
}