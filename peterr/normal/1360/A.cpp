#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        int s = max(a, 2 * b);
        cout << s * s << "\n";
    }
    return 0;
}