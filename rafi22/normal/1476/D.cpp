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

int lastP[300007];
int lastS[300007];

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
        string s;
        cin>>n>>s;
        s='#'+s+'#';
        lastP[0]=1;
        for(int i=1;i<sz(s)-1;i++)
        {
            if(s[i]==s[i-1]) lastP[i]=i;
            else lastP[i]=lastP[i-1];
        }
        lastS[sz(s)-1]=sz(s)-2;
        for(int i=sz(s)-2;i>0;i--)
        {
            if(s[i]==s[i+1]) lastS[i]=i;
            else lastS[i]=lastS[i+1];
        }
        for(int i=1;i<=n+1;i++)
        {
            int ans=1;
            if(s[i-1]=='L') ans+=i-lastP[i-1];
            if(s[i]=='R') ans+=lastS[i]-i+1;
            cout<<ans<<" ";
        }
        cout<<endl;

    }

    return 0;
}