#include <bits/stdc++.h>

using namespace std;
int n, t[15], sum;
bool jo=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    for (int i=0; i<(1<<n); i++) {
        sum=0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                sum+=t[j];
            } else {
                sum-=t[j];
            }
        }
        if (sum%360==0) {
            jo=1;
        }
    }
    cout << (jo? "YES" : "NO") << "\n";
    return 0;
}