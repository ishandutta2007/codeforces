#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int ans1[MAXN];
int ans2[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 0)
    {
        cout << "Yes\n";
        for (int i = 0; i < b; i++)
            cout << 1;
        for (int i = 0; i < a; i++)
            cout << 0;
        cout << "\n";
        for (int i = 0; i < b; i++)
            cout << 1;
        for (int i = 0; i < a; i++)
            cout << 0;
        return 0;
    }
    if (a == 0)
    {
        cout << "No\n";
        return 0;
    }
    if (k > a + b - 2)
    {
        cout << "No\n";
        return 0;
    }
    if (b == 1)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    ans2[0] = 1;
    for (int i = 0; i < b - 1; i++)
        ans2[i + a + 1] = 1;
    copy(ans2, ans2 + a + b, ans1);
    int ptr = a + 1;
    while (k && ptr >= 2)
    {
        ans1[ptr] = 0;
        ans1[ptr - 1] = 1;
        k--;
        ptr--;
    }
    ptr = a + 2;
    while (k)
    {
        ans1[ptr] = 0;
        ans1[ptr - 1] = 1;
        ptr++;
        k--;
    }
    for (int i = 0; i < a + b; i++)
        cout << ans1[i];
    cout << "\n";
    for (int i = 0; i < a + b; i++)
        cout << ans2[i];
    cout << "\n";
    return 0;
}