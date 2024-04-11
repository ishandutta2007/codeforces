#include <bits/stdc++.h>

//#define int long long
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

const int N=100007;

int l[N],r[N];
int ans[37];


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
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
        for(int j=0;j<30;j++)
        {
            int c=0;
            vector<pair<int,int>>P;
            for(int i=1;i<=n;i++)
            {
                if(r[i]-l[i]+1>=(1<<j)) c++;
                else
                {
                    int x=l[i]%(1<<j),y=(r[i]+1)%(1<<j);
                    if(x<=y)
                    {
                        P.pb({x,1});
                        P.pb({y,-1});
                    }
                    else
                    {
                        P.pb({x,1});
                        P.pb({0,1});
                        P.pb({y,-1});
                    }
                }
            }
            sort(all(P));
            int mx=0,b=0;
            for(int i=0;i<sz(P);i++)
            {
                b+=P[i].nd;
                if(i==sz(P)-1||P[i].st!=P[i+1].st) mx=max(mx,b);
            }
            ans[j]=mx+c;
        }
        int q;
        cin>>q;
        while(q--)
        {
            int x;
            cin>>x;
            for(int j=0;j<30;j++)
            {
                if((x&(1<<j)))
                {
                    cout<<ans[j]<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}