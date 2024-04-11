#include <bits/stdc++.h>

using namespace std;
long long w, x1, x2;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> s;
        int si=s.size();
        x1=0, x2=0;
        for (int i=0; i<si; i++) {
            int ert=(s[i]-'0');
            if (i%2) {
                x1=10*x1+ert;
            } else {
                x2=10*x2+ert;
            }
        }

        cout << (x1+1)*(x2+1)-2 << "\n";
    }
    return 0;
}