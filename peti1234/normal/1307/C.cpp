#include <bits/stdc++.h>

using namespace std;
const int c=32;
long long db[c], ert[c][c], n, maxi;
string s;
int main()
{
    cin >> s, n=s.size();
    for (int i=0; i<n; i++) {
        int x=s[i]-'a';
        for (int i=0; i<c; i++) {
            ert[i][x]+=db[i];
            maxi=max(maxi, ert[i][x]);
        }
        db[x]++;
        maxi=max(maxi, db[x]);
    }
    cout << maxi << "\n";
    return 0;
}