#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int mini, n, t[c], kom[c];
int main()
{
    cin >> n;
    mini=n+1;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]^t[i];
    }
    if (n>100) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=i; k<j; k++) {
                if ((kom[k]^kom[i-1])>(kom[j]^kom[k])) {
                    mini=min(mini, j-i-1);
                }
            }
        }
    }
    if (mini>n) mini=-1;
    cout << mini << endl;
    return 0;
}