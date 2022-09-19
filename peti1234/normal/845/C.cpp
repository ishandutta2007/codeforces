#include <bits/stdc++.h>

using namespace std;
int n;
int k[200001];
int v[200001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> k[i] >> v[i];
    }
    sort(k+1, k+n+1);
    sort(v+1, v+n+1);
    for (int i=1; i<n-1; i++) {
        if (v[i]>=k[i+2]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}