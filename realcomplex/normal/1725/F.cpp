#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define en cin.close();return 0;
#define pb push_back
#define fi first//printf("%lli\n",cur);
#define se second//scanf("%lli",&n);
#define r0 return 0;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
    fio
    //ifstream cin("in.in");
    int n;
    cin >> n;
    pair<int,int> p[n];
    for(auto &x:p)
        cin >> x.fi >> x.se;
    int ans[32];
    for(int i = 0;i<30;i++)
    {
        int dpak = (1<<i);
        vector<pair<int,bool> > seg;
        int pl = 0;
        for(auto x:p)
        {
            if(x.se-x.fi+1>=dpak)
                pl++;
            else
            {
                int l = x.fi%dpak, r = x.se%dpak;
                if(l<=r)
                    seg.pb({l,0}),
                    seg.pb({r,1});
                else
                    seg.pb({0,0}),
                    seg.pb({r,1}),
                    seg.pb({l,0}),
                    seg.pb({dpak-1,1});
            }
        }
        sort(seg.begin(),seg.end());
        int cur = 0, mx = pl;
        for(auto x:seg)
            cur+=(x.se==0?1:-1),
            mx=max(mx,pl+cur);
        ans[i]=mx;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int w;
        cin >> w;
        int t = 0;
        while(((1<<t)&w)==0)
            t++;
        cout << ans[t] << "\n";
    }
    //cin.close();
    return 0;
}