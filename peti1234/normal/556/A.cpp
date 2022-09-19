#include <bits/stdc++.h>

using namespace std;
int n, a, b;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        (c=='0' ? a++ : b++);
    }
    cout << abs(a-b) << "\n";
    return 0;
}