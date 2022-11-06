#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        while (1)
        {
            string s = to_string(n);
            int sum = 0;
            for (char ch : s)
                sum += ch - '0';
            if (__gcd((long long) sum, n) > 1)
                break;
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}