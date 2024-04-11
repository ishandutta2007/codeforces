#include <bits/stdc++.h>

using namespace std;

vector <int> a, d;

int main()
{
    int n, x;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans1 = 1;
    int ans = -1000000;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, ans1);
        if (a[i] >= a[i - 1])
            ans1++;
        else
            ans1 = 1;
    }
    ans = max(ans, ans1);
    cout << ans;
    return 0;
}