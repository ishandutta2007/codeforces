#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];

void solve(int m, string &s, string &t, int arr[MAXN])
{
    int ptr = 0;
    for (int i = 0; i < m; i++)
    {
        while (s[ptr] != t[i])
            ptr++;
        arr[i] = ptr;
        ptr++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    solve(m, s, t, a);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    solve(m, s, t, b);
    int ans = 0;
    for (int i = 0; i < m - 1; i++)
    {
        ans = max(ans, (n - 1 - b[m - i - 2]) - a[i]);
    }
    cout << ans << "\n";
    return 0;
}