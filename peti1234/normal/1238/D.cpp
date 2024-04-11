#include <bits/stdc++.h>

using namespace std;
long long n, h, db, kezd, veg;
string s;
int main()
{
    cin >> n >> s;
    h=1;
    for (int i=1; i<n; i++) {
        if (s[i]!=s[i-1]) {
            db++;
            if (db==1) {
                kezd=h;
            }
            h=0;
        }
        h++;
    }
    veg=h;
    if (!db) {
        kezd=h;
    }
    cout << n*(n-1)/2-2*n+kezd+veg+db << "\n";
    return 0;
}