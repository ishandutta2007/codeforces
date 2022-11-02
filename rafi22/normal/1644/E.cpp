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

int sx[200007];
int sy[200007];

signed main()
{
    mod=mod1;
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
        string s;
        cin>>s;
        int m=sz(s);
        int x=1,y=1;
        int ans=0;
        sx[m]=0,sy[m]=0;
        for(int i=m-1;i>=0;i--)
        {
            sx[i]=sx[i+1]+(s[i]=='D');
            sy[i]=sy[i+1]+(s[i]=='R');
        }
        for(int i=0;i<m;i++)
        {
            if(s[i]=='D')
            {
                if(y>1) ans+=sy[i];
                else ans+=n-1;
                x++;
            }
            if(s[i]=='R')
            {
                if(x>1) ans+=sx[i];
                else ans+=n-1;
                y++;
            }
        }
        if(x==1) ans+=(n-1)*(n-y+1);
        if(y==1) ans+=(n-1)*(n-x+1);
        cout<<n*n-ans<<endl;
    }

    return 0;
}