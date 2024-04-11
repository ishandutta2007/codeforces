#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
const int N=512;
int cnt[N+10];
int c[N+10];
int ind[N+10];
vector<pair<int,int> >g[N+10];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        int f;cin>>f;
        int mask=0;
        for (int j=1;j<=f;j++){
            int x;cin>>x;
            mask|=(1<<(x-1));
        }
        cnt[mask]++;
    }
    for (int i=1;i<=m;i++){
        int cur;cin>>cur;
        int r;cin>>r;
        int mask=0;
        for (int j=1;j<=r;j++){
            int x;cin>>x;
            mask|=(1<<(x-1));
        }
        if (!c[mask] || c[mask]>cur){
            c[mask]=cur;
            ind[mask]=i;
        }
        g[mask].push_back({cur,i});
    }
    pair<pair<int,int>,pair<int,int> >res={{0,-2000000001},{0,0}};
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            if (!c[i] || !c[j]) continue;
            int cur=(i|j);
            int cn=0;
            for (int t=0;t<N;t++){
                if ((cur&t)==t) {
                    cn+=cnt[t];
                }
            }
            pair<pair<int,int>,pair<int,int> >x={{cn,-c[i]-c[j]},{ind[i],ind[j]}};
            res=max(res,x);
        }
    }
    for (int i=0;i<N;i++){
        if (g[i].size()<2) continue;
        sort(g[i].begin(),g[i].end());
        int cn=0;
        for (int j=0;j<N;j++){
            if ((i&j)==j){
                cn+=cnt[j];
            }
        }
        int cost=g[i][0].first+g[i][1].first;
        int ind1=g[i][0].second;
        int ind2=g[i][1].second;
        pair<pair<int,int>,pair<int,int> >x={{cn,-cost},{ind1,ind2}};
        res=max(res,x);

    }
    cout<<res.second.first<<" "<<res.second.second;
    return 0;
}
//2 6 -2 -6  2