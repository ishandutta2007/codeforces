#include <bits/stdc++.h>

using namespace std;
string s;
int n, p, q;
int main()
{
    cin >> n >> p >> q >> s;
    for (int i=0; i<=100; i++) {
        for (int j=0; j<=100; j++) {
            if (p*i+q*j==n) {
                cout << i+j << "\n";
                int pos=0;
                for (int k=0; k<i; k++) {
                    cout << s.substr(pos, p) << "\n";
                    pos+=p;
                }
                for (int k=0; k<j;k++) {
                    cout << s.substr(pos, q) << "\n";
                    pos+=q;
                }
                return 0;
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}