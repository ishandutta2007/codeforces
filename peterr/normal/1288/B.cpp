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
        long long ans = 0;
        long long nine = 9;
        while (nine <= b)
        {
            ans++;
            nine = nine * 10 + 9;
        }
        ans *= a;
        cout << ans << endl;
    }
    return 0;
}