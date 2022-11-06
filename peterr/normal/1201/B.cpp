#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    int big = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        big = max(big, a);
    }
    if (sum % 2 == 0 && big * 2 <= sum)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}