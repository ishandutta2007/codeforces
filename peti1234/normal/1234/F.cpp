#include <bits/stdc++.h>

using namespace std;
const int c2=20, c=1<<20;
string s;
int db[c], maxi, n;
int main()
{
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        int mask=0;
        for (int j=i; j<n; j++) {
            int ert=(s[j]-'a');
            ert=(1<<ert);
            if (mask & ert) {
                break;
            }
            mask+=ert;
            db[mask]=__builtin_popcount(mask);
        }
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<c2; j++) {
            int ert=(1<<j);
            if (i & ert) {
                continue;
            }
            db[i+ert]=max(db[i+ert], db[i]);
        }
    }
    for (int i=0; i<c; i++) {
        maxi=max(maxi, db[i]+db[c-1-i]);
    }
    cout << maxi << "\n";
    return 0;
}