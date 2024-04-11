#include <bits/stdc++.h>

using namespace std;
const int c=102;
int n, t[c], sum, s;
bool v[1000002];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s=__gcd(s, t[i]);
    }
    for (int i=1; i<=n; i++) {
        t[i]/=s;
        sum+=t[i];
    }

    v[0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=sum; j>=0; j--) {
            if (v[j]) {
                v[j+t[i]]=1;
            }
        }
    }
    /*
    for (int i=0; i<=sum; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    */
    if (sum%2 || !v[sum/2]) {
        cout << 0 << "\n";
        return 0;
    }
    cout << 1 << "\n";
    for (int i=1; i<=n; i++) {
        if (t[i]%2) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
/*
4
6 3 9 12
*/