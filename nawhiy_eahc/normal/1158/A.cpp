#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll b[100002], g[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=m;i++) cin >> g[i];

    ll B = -1, S = 1e8, cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(b[i] > B) { B = b[i]; cnt = 1; }
        else if(b[i] == B) cnt++;
    }
    for(int i=1;i<=m;i++) S = min(S, g[i]);
    ll ans = 0;
    if(B > S)
    {
        ans = -1;
    }
    else if(B == S || cnt > 1)
    {
        for(int i=1;i<=n;i++)
        {
            ans += 1LL * b[i] * m;
        }
        for(int i=1;i<=m;i++)
        {
            ans += g[i] - B;
        }
    }
    else
    {
        int M = -1;
        for(int i=1;i<=n;i++)
        {
            if(b[i] > M && b[i] != B) M = b[i];
        }

        for(int i=1;i<=n;i++)
        {
            ans += 1LL * b[i] * m;
        }
        for(int i=1;i<=m;i++)
        {
            ans += g[i] - B;
        }

        ans += B - M;
    }

    cout << ans;
}