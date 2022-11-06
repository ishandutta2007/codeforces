#include <bits/stdc++.h>

using namespace std;

bool check(int x, int n, int k)
{
    long long candies = (long long) x * (x + 1) / 2;
    candies -= n - x;
    return candies <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int add = 0;
    for (int jump = n / 2 + 1; jump > 0; jump /= 2)
    {
        while (add + jump <= n && check(add + jump, n, k))
            add += jump;
    }
    cout << n - add;
    return 0;
}