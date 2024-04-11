#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x[200002], y[200002];
int M[450][450];
int v[200002];
int ans[200002];
int lef[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
    for(int i=1;i<=m;i++)
    {
        int op, k; cin >> op >> k;
        if(op == 2)
        {
            if(x[k] + y[k] <= 447)
            {
                int now = lef[k] + x[k];
                int p = x[k] + y[k];
                for(int j=1;j<=y[k];j++)
                {
                    M[p][now%p]--;
                    now++;
                }
            }
            else
            {
                ll now = lef[k];
                while(now <= m)
                {
                    now += x[k];
                    if(i <= now && now <= m) v[now]--;
                    now += y[k]; if(now - y[k] < i && now >= i) v[i]--;
                    if(i <= now && now <= m) v[now]++;
                }
            }
            for(int j=1;j<=447;j++) ans[i] += M[j][i%j];
            continue;
        }
        for(int j=1;j<=447;j++) ans[i] += M[j][i%j];
        lef[k] = i;
        if(x[k] + y[k] <= 447)
        {
            int p = x[k] + y[k];
            int now = i+x[k];
            for(int j=1;j<=y[k];j++)
            {
                M[p][now%p]++;
                now++;
            }
        }
        else
        {
            ll now = i;
            while(now <= m)
            {
                now += x[k];
                if(now <= m) v[now]++;
                now += y[k];
                if(now <= m) v[now]--;
            }
        }
    }
    for(int i=2;i<=m;i++) v[i] += v[i-1];
    for(int i=1;i<=m;i++) cout << v[i] + ans[i] << "\n";
}