#include <bits/stdc++.h>

using namespace std;
long long w, x, a, b;
int main()
{
    cin >> w;
    while (w--) {
        cin >> x, a=1, b=1e4;
        bool jo=0;
        while (a<=1e4 && b) {
            long long ert=a*a*a+b*b*b;
            if (ert==x) {
                jo=1;
                break;
            }
            if (ert>x) {
                b--;
            }
            if (ert<x) {
                a++;
            }
        }
        cout << (jo? "YES" : "NO") << "\n";
    }
    return 0;
}