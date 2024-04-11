#include <bits/stdc++.h>

using namespace std;
int n, p, a, b, c, ra, rb, rc;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s, p=n/3;
    for (int i=0; i<n; i++) {
        if (s[i]=='0') a++;
        if (s[i]=='1') b++;
        if (s[i]=='2') c++;
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='0') {
            if (ra==p) {
                a--;
                if (b<p) {
                    cout << 1;
                    b++, rb++;
                } else {
                    cout << 2;
                    c++, rc++;
                }
            } else {
                cout << 0;
                ra++;
            }
        }
        if (s[i]=='1') {
            if (b>p && a<p) {
                cout << 0;
                a++, b--, ra++;
            } else if (rb==p) {
                cout << 2;
                c++, b--, rc++;
            } else {
                cout << 1;
                rb++;
            }
        }
        if (s[i]=='2') {
            if (c>p) {
                if (a<p) {
                    cout << 0;
                    a++, c--, ra++;
                } else {
                    cout << 1;
                    b++, c--, rb++;
                }
            } else {
                cout << 2;
                rc++;
            }
        }
    }
    cout << "\n";
    return 0;
}