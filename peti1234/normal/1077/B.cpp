#include <bits/stdc++.h>

using namespace std;
int n, k, t[105];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (i>=3 && t[i]==1 && t[i-2]==1 && t[i-1]==0) {
            k++;
            t[i]=0;
        }
    }
    cout << k << "\n";
    return 0;
}