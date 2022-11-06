#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
int early[MAXN];
int late[MAXN];

int main()
{
    string s, t;
    cin >> s >> t;
    int ptr = 0;
    for (int i = 0; i < (int) t.length(); i++)
    {
        while (s[ptr] != t[i])
            ptr++;
        early[i] = ptr++;
    }
    ptr = (int) s.length() - 1;
    for (int i = (int) t.length() - 1; i >= 0; i--)
    {
        while (s[ptr] != t[i])
            ptr--;
        late[i] = ptr--;
    }
    int ans = max(late[0], ((int) s.length() - 1) - early[(int) t.length() - 1]);
    for (int i = 1; i < (int) t.length(); i++)
    {
        ans = max(ans, late[i] - early[i - 1] - 1);
    }
    cout << ans << endl;
    return 0;
}