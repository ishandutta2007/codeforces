#include <bits/stdc++.h>

using namespace std;

long long sum(int x)
{
    return (long long) x * (x + 1) / 2;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    int p = a;
    for (int sum = c + 1; sum <= b + c; sum++)
    {
        while (p <= b && p + c < sum)
            p++;
        if (p > b)
            break;
        if (sum - p < b)
            continue;
        int num = min(b - p + 1, (sum - p) - b + 1);
        ans += (long long) num * min(sum - c, d - c + 1);
    }
    cout << ans << "\n";
    return 0;
}