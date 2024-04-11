#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n<=2) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << 1 << " ";
    int x=0;
    if (n%2==0) {
        x=n/2;
    } else {
        x=n;
    }
    cout << x << endl;
    cout << n-1 << " ";
    for (int i=1; i<=n; i++) {
        if (i!=x) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}