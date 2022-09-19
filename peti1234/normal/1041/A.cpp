#include <bits/stdc++.h>

using namespace std;
int mini=INT_MAX;
int maxi=0;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        mini=min(mini, x);
        maxi=max(maxi, x);
    }
    cout << maxi-mini-n+1 << endl;
    return 0;
}