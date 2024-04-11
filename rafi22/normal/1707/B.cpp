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

const bool multi=1;

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
        int n,x;
        cin>>n;
        vector<int>V;
        int c0=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==0) c0++;
            else V.pb(x);
        }
        for(int i=1;i<n;i++)
        {
            sort(all(V));
            vector<int>V1;
            bool x=c0>0;
            for(int j=0;j<sz(V);j++)
            {
                if(j==0)
                {
                    if(c0>0) V1.pb(V[j]);
                }
                else
                {
                    if(V[j]==V[j-1]) c0++;
                    else V1.pb(V[j]-V[j-1]);
                }
            }
            V=V1;
            c0-=x;
        }
        if(sz(V)==0) cout<<0<<endl;
        else cout<<V[0]<<endl;
    }

    return 0;
}