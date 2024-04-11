#include <bits/stdc++.h>

using namespace std;
string s;
int a, x;
int main()
{
    cin >> s;
    for (char i:s) {
        if (i=='a') {
            a++;
        } else {
            x++;
        }
    }
    cout << a+min(x, a-1) << "\n";
    return 0;
}