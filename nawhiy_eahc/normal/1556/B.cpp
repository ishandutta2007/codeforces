#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        if(n == 1)
        {
            cout << "0\n";
            continue;
        }

        int next = 1;
        ll tmp = 0, ans = INF;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2 == 0)
            {
                tmp += abs(next - i);
                next += 2;
            }
        }

        if(next == n+1 || next == n+2)
        {
            ans = min(tmp, ans);
        }

        tmp = 0;
        next = 2;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2 == 0)
            {
                tmp += abs(next- i);
                next += 2;
            }
        }
        if(next == n+1 || next == n+2)
        {
            ans = min(tmp, ans);
        }

        if(ans == INF)
        {
            cout << "-1\n";
        }
        else cout << ans << "\n";
    }
}