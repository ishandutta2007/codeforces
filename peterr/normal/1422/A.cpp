#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        long long d = (long long) a + b + c - 1;
        cout << d << "\n";
    }
    return 0;
}