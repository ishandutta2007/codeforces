#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

int ask(int w)
{
    cout<<"? "<<w<<endl;
    int h;
    cin>>h;
    return h;
}

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
        int l=1,r=4100000,sr,S;
        while(l<=r)
        {
            sr=(l+r)/2;
            if(ask(sr)==1)
            {
                S=sr;
                r=sr-1;
            }
            else l=sr+1;
        }
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            int w=S/i;
            int x=w*ask(w);
            if(x>0) ans=min(ans,x);
        }
        cout<<"! "<<ans<<endl;
    }

    return 0;
}