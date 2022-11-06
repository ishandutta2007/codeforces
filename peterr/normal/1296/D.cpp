#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    vector<int> delta;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        int lessH = h % (a + b);
        if (lessH == 0)
            lessH = a + b;
        if (lessH <= a)
            ans++;
        else
        {
            delta.push_back((lessH + a - 1) / a - 1);
        }
    }
    sort(delta.begin(), delta.end());
    int ptr = 0;
    while (ptr < (int) delta.size() && delta[ptr] <= k)
    {
        ans++;
        k -= delta[ptr];
        ptr++;
    }
    cout << ans << endl;
    return 0;
}