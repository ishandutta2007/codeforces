#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int P[50007][6];

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
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>P[i][j];
            }
        }
        deque<int>Q;
        for(int i=1;i<=n;i++) Q.pb(i);
        while(sz(Q)>1)
        {
            int x=Q[0];
            int y=Q[1];
            Q.pop_front();
            Q.pop_front();
            int cnt=0;
            for(int j=1;j<=5;j++) if(P[x][j]<P[y][j]) cnt++;
            if(cnt>=3) Q.push_front(x);
            else
            {
                cnt=0;
                for(int j=1;j<=5;j++) if(P[y][j]<P[x][j]) cnt++;
                if(cnt>=3) Q.push_front(y);
            }
        }
        if(sz(Q)==0) cout<<-1<<endl;
        else
        {
            int x=Q[0];
            bool ans=1;
            for(int i=1;i<=n;i++)
            {
                if(i==x) continue;
                int cnt=0;
                for(int j=1;j<=5;j++) if(P[x][j]<P[i][j]) cnt++;
                if(cnt<3) ans=0;
            }
            if(ans) cout<<x<<endl;
            else cout<<-1<<endl;
        }
    }

    return 0;
}