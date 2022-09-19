#include <bits/stdc++.h>

using namespace std;
int n;
string k;
int a=0, d=0;
int main()
{
    cin >> n;
    cin >> k;
    for (int i=0; i<n; i++) {
        if (k[i]=='A') {
            a++;
        }
        if (k[i]=='D') {
            d++;
        }
    }
    if (a>d) {
        cout << "Anton";
    }
    if (d>a) {
        cout << "Danik";
    }
    if (a==d) {
        cout << "Friendship";
    }
    return 0;
}