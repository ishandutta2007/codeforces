#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, t;
        cin >> n >> s >> t;
        cout << (n - min(s, t) + 1) << endl;
    }
    return 0;
}