#include <bits/stdc++.h>

using namespace std;
int n, f[10], kezd, veg;
string s;
int main()
{
    cin >> n >> s;
    for (int i=1; i<=9; i++) {
        cin >> f[i];
    }
    for (int i=0; i<n; i++) {
        int a=s[i]-'0', b=f[a];
        if (b>a && !veg) {
            kezd=1;
            cout << b;
            continue;
        }
        if (b<a) {
            if (kezd) {
                veg=1;
            }
        }
        cout << a;
    }
    cout << "\n";
    return 0;
}