#include <bits/stdc++.h>

using namespace std;

long long solve(int a, int b, long long x)
{
    long long cycles = x / b;
    long long other = a * b / __gcd(a, b) / b;
    long long ans = 0;
    if (cycles)
    {
        ans += ((cycles - 1) / other + 1) * b;
    }
    //(max(cycles - 1, 0LL) / other) * b;
    long long num = x / b;
    if (num % other == 0)
    {
        ans += x % b + 1;
    }
    //cout << other << endl;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, q;
        cin >> a >> b >> q;
        if (a > b)
            swap(a, b);
        while (q--)
        {
            long long l, r;
            cin >> l >> r;
            cout <<  (r - l + 1) - (solve(a, b, r) - solve(a, b, l - 1)) << " ";
        }
        cout << "\n";
    }
    return 0;
}