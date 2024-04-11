#include <bits/stdc++.h>

using namespace std;
int s1, s2, db1, db2, n;
int main()
{
    cin >> n;
    for (int i=0; i<n/2; i++) {
        char c;
        cin >> c;
        if (c=='?') {
            db1++;
        } else {
            s1+=(c-'0');
        }
    }
    for (int i=0; i<n/2; i++) {
        char c;
        cin >> c;
        if (c=='?') {
            db2++;
        } else {
            s2+=(c-'0');
        }
    }

    cout << (2*s1+9*db1==2*s2+9*db2 ? "Bicarp" : "Monocarp") << "\n";
    return 0;
}