#include <bits/stdc++.h>

using namespace std;
int n, pos, ne;
string a, b;
int main()
{
    cin >> n >> a >> b;
    pos=n;
    if (a==b) {
        cout << a << "\n";
        return 0;
    }
    for (int i=0; i<n; i++) {
        if (a[i]!=b[i]) {
            ne=i;
            break;
        }
    }
    if (a[0]=='0') {
        for (int i=0; i<n; i++) {
            cout << 1;
        }
        cout << "\n";
        return 0;
    }
    for (int i=0; i<n; i++) {
        if (b[i]=='0' && i>ne) {
            pos=i;
            break;
        }
    }
    if (b[n-2]=='1') {
        b[n-1]='1';
    }
    if (b[n-1]=='0') {
        for (int j=ne+1; j<n; j++) {
            if (a[j]=='0') {
                b[n-1]='1';
            }
        }
    }
    cout << b << "\n";
    return 0;
}