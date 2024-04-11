#include <bits/stdc++.h>

using namespace std;
int w;
string s, o, e;
int main()
{   
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        for (auto x:s) {
            if ((x-'0')%2) {
                o+=x;
            } else {
                e+=x;
            }
        }
        int si=e.size(), pos=0;
        for (auto x:o) {
            while (pos<si && e[pos]<x) {
                cout << e[pos++];
            }
            cout << x;
        }
        while (pos<si) {
            cout << e[pos++];
        }
        cout << "\n";
        o.clear(), e.clear();
    }
    return 0;
}