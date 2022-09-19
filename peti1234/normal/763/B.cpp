#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    cout << "YES" << endl;
    for (int i=1; i<=n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a%2==0 && b%2==0) {
            cout << 1 << endl;
        }
        if (a%2!=0 && b%2==0) {
            cout << 2 << endl;
        }
        if (a%2==0 && b%2!=0) {
            cout << 3 << endl;
        }
        if (a%2!=0 && b%2!=0) {
            cout << 4 << endl;
        }
    }
    return 0;
}