#include <bits/stdc++.h>

using namespace std;
int n;
string s;
bool jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s, n=s.size();
    for (int i=1; i<n/2; i++) {
        if (s[i]!=s[i-1]) jo=1;
    }
    if (!jo) {
        cout << "Impossible\n";
        return 0;
    }
    if (n%2) {
        cout << 2 << "\n";
        return 0;
    }
    while(true) {
        bool x=0;
        for (int i=0; i<n; i++) {
            if (s[i]!=s[n-i-1]) x=1;
        }
        if (x) {
            cout << 1 << "\n";
            return 0;
        }
        if (n%2) {
            cout << 2 << "\n";
            return 0;
        }
        n/=2;
    }
    return 0;
}