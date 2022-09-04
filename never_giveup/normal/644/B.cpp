#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

queue<ll> q;

int n, sz;

const int maxn = 1e6;

ll ans[maxn];

pair<ll, ll> p[maxn];

int main()
{
    cin >> n >> sz;
    for (int i = 0; i < n; i++)
        ans[i] = -1, cin >> p[i].first >> p[i].second;
    int i = 0;
    ll tm, d, ind;
    ll now = 0;
    while (1){
        if (!q.empty()){
            ind = q.front();
            tm = p[ind].first;
            d = p[ind].second;
            now = max(now, tm);
            now += d;
            ans[ind] = now;
            q.pop();
            while (i < n && p[i].first < now){
                if (q.size() < sz)
                    q.push(i);
                i++;
            }
        }
        if (q.empty())
            if (i == n)
                break;
            else
                q.push(i), i++;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}