#include <bits/stdc++.h>

using namespace std;
int n;
int a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
        bool c=(s[i]=='(');
        if (c==1) {
            if (a<b) {
                cout << 0;
                a++;
            } else {
                cout << 1;
                b++;
            }
        } else {
            if (a>b) {
                cout << 0;
                a--;
            } else {
                cout << 1;
                b--;
            }
        }
    }
    cout << endl;
    return 0;
}