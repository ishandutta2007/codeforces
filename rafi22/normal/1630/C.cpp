#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[200007];
int last[200007];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=n;i>0;i--) if(!last[a[i]]) last[a[i]]=i;
        deque<pair<int,int>>Q;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            while(sz(Q)>0&&Q[0].nd==i) Q.pop_front();
            if(last[a[i]]<=i) continue;
            int j=last[a[i]];
            if(sz(Q)==0)
            {
                Q.pb({i,j});
                ans+=j-i-1;
            }
            else if(sz(Q)==1)
            {
                if(j>Q[0].nd)
                {
                    Q.pb({i,j});
                    ans+=j-Q[0].nd-1;
                }
            }
            else if(sz(Q)==2)
            {
                if(j>Q[1].nd)
                {
                    ans+=j-Q[1].nd;
                    Q.pop_back();
                    Q.pb({i,j});
                }
            }
        }
        cout<<ans;
    }

    return 0;
}