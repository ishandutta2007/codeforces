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
    int times = (a + b - 1) / b;
    cout << (long long) b * times - a << endl;
    }
    return 0;
}