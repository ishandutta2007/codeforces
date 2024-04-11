#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b%3==0) {
            a%=(b+1);
            cout << (a==b || a%3 ? "Alice" : "Bob") << "\n";
        } else {
            cout << (a%3 ? "Alice" : "Bob") << "\n";
        }
    }
    return 0;
}