#include <bits/stdc++.h>

using namespace std;
string x, z, y;
int main()
{
    cin >> x >> z;
    for (int i=0; i<x.size(); i++) {
        if (x[i]<z[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i=0; i<z.size(); i++) {
        cout << z[i];
    }
    return 0;
}