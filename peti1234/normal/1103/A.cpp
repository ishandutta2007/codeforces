#include <bits/stdc++.h>

using namespace std;
int a=0, b=0;
int main()
{
    string s;
    cin >> s;
    for (auto x:s) {
        if (x=='0') {
            cout << 1 << " " << a%4+1 << "\n";
            a++;
        } else {
            cout << 3 << " " << b%2*2+1 << "\n";
            b++;
        }
    }
    return 0;
}