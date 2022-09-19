#include <bits/stdc++.h>

using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    int a=n-k;
    a/=2;
    a++;
    if (k==1) {
        for (int i=1; i<n; i++) {
            cout << 1;
        }
        cout << 0;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if ((i%a)==0 || (a!=2 && i%a==1)) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}