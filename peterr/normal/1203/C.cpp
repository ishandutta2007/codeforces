#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> divv;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long g = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (i == 0)
            g = a;
        else
            g = __gcd(g, a);
    }
    for (int i = 2; g > 1 && (long long) i * i <= g; i++)
    {
        while (g % i == 0)
        {
            if (divv.find(i) == divv.end())
                divv[i] = 1;
            else
                divv[i]++;
            g /= i;
        }
    }
    if (g > 1)
    {
        divv[g] = 1;
    }
    long long ans = 1;
    for (auto it = divv.begin(); it != divv.end(); it++)
    {
        ans *= it->second + 1;
    }
    cout << ans << endl;


    return 0;
}