#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>

using namespace std;

vector<pii> latarki;
vector<pii> zlodzieje;

const int nax = 1e6 + 7;

int dist[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x,y ;cin>>x>>y;
        zlodzieje.pb(mp(x,y));
    }
    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        latarki.pb(mp(x,y));
    }

    int ans = 2e9 + 5;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int v1 = zlodzieje[i].st;
            int v2 = latarki[j].st;
            int d = v2 - v1;
            if(d >= 0)
            {
                int need = latarki[j].nd - zlodzieje[i].nd + 1;
                dist[d] = max(dist[d],need);
            }
        }
    }

    int cur = 1e6 + 5;
    for(int i=cur;i>=0;i--)
    {
        dist[i] = max(dist[i],dist[i+1]);
        int xd = i + dist[i];
        ans = min(ans,xd);
    }

    cout<<ans;




    return 0;
}