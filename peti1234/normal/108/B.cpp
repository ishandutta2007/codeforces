#include <bits/stdc++.h>

using namespace std;
int n, t[100000];
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) cin >> t[i];
    sort(t, t+n);
    for (int i=0; i<n-1; i++) {
        if (t[i]<t[i+1] && 2*t[i]>t[i+1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}