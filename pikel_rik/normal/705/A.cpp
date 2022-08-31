#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "I hate that", s2 = "I love that";
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        if (i % 2 != 0)
            cout << s1 << " ";
        else
            cout << s2 << " ";
    }
    if (n % 2 == 0)
        cout << "I love it";
    else
        cout << "I hate it";
    
    return 0;
}