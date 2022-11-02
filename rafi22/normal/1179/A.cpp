#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

pair<int,int>ans[300007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,q,mx=0,a;
        cin>>n>>q;
        deque<int>D;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            mx=max(mx,a);
            D.pb(a);
        }
        deque<pair<int,int>>Q;
        for(int i=1;i<=q;i++)
        {
            cin>>a;
            Q.pb({a,i});
        }
        sort(Q.begin(),Q.end());
        int it=0;
        while(D[0]!=mx)
        {
            int x=D[0];
            int y=D[1];
            D.pop_front();
            D.pop_front();
            D.push_front(max(x,y));
            D.pb(min(x,y));
            it++;
            while(!Q.empty()&&Q[0].st==it)
            {
                ans[Q[0].nd]={x,y};
                Q.pop_front();
            }
        }
        for(auto x:Q) ans[x.nd]={mx,D[1+(x.st-it-1)%(sz(D)-1)]};
        for(int i=1;i<=q;i++) cout<<ans[i].st<<" "<<ans[i].nd<<endl;
    }

    return 0;
}