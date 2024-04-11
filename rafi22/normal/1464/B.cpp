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

const bool multi=0;

const int N=100007;

int pref0[N];
int pref1[N];
int suf0[N];
int suf1[N];
int xd[N];
vector<int>z;

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
        string s;
        cin>>s;
        int x,y,sum=0,ans=inf;
        cin>>x>>y;
        s='#'+s;
        int n=sz(s)-1;
        for(int i=1;i<=n;i++)
        {
            pref0[i]=pref0[i-1];
            pref1[i]=pref1[i-1];
            if(s[i]=='0') pref0[i]++;
            if(s[i]=='1') pref1[i]++;
        }
        for(int i=n;i>0;i--)
        {
            suf0[i]=suf0[i+1];
            suf1[i]=suf1[i+1];
            if(s[i]=='0') suf0[i]++;
            if(s[i]=='1') suf1[i]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') sum+=x*suf1[i];
            else if(s[i]=='1') sum+=y*suf0[i];
            else z.pb(i);
        }
        for(int j=sz(z)-1;j>=0;j--) xd[j]=xd[j+1]+pref1[z[j]]*y+suf1[z[j]]*x;
        int act=0;
        for(int j=0;j<=sz(z);j++)
        {
           // cout<<act+xd[j]<<endl;
            ans=min(ans,act+xd[j]+j*(sz(z)-j)*y);
            if(j!=sz(z)) act+=pref0[z[j]]*x+suf0[z[j]]*y;
        }
        for(int j=sz(z)-1;j>=0;j--) xd[j]=xd[j+1]+pref0[z[j]]*x+suf0[z[j]]*y;
        act=0;
        for(int j=0;j<=sz(z);j++)
        {
            ans=min(ans,act+xd[j]+j*(sz(z)-j)*x);
            if(j!=sz(z)) act+=pref1[z[j]]*y+suf1[z[j]]*x;
        }
        cout<<ans+sum<<endl;
    }

    return 0;
}