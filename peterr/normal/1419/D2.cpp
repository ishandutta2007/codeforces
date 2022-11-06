#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ptr = 0;
    for (int i = 1; i < n; i += 2)
    {
        ans[i] = a[ptr];
        ptr++;
    }
    for (int i = 0; i < n; i += 2)
    {
        ans[i] = a[ptr];
        ptr++;
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
            cnt++;
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
    return 0;
}