#include <bits/stdc++.h>

using namespace std;
long long n, x, db[28];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    cin >> s;
    for (int i=0; i<n; i++) {
        int p=s[i]-'a', ert=(1<<p);
        if (i<n-2) {
            x+=ert;
            db[p+1]++;
        }
        if (i==n-2) {
            x+=ert;
        }
        if (i==n-1) {
            x-=ert;
        }
    }
    if (x<0) {
        cout << "NO\n";
        return 0;
    }
    for (long long i=26; i>=0; i--) {
        x-=(1<<i)*min(db[i], x/(1<<i));
    }
    if (x==0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}