#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long k;
        int x;
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }
    return 0;
}