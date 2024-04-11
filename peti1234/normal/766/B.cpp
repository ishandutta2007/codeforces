#include <bits/stdc++.h>

using namespace std;
int n;
long long t[100001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort (t+1, t+n+1);
    for (int i=1; i<n-1; i++) {
        if (t[i]+t[i+1]>t[i+2]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}