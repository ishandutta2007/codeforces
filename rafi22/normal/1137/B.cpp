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

int c[2];
int c1[2];
int c2[2];
int p[500007];


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
        string s,t;
        cin>>s>>t;
        for(auto x:s) c[x-'0']++;
        for(auto x:t) c1[x-'0']++;
        t='#'+t;
        p[0]=-1;
        int x=-1;
        for(int i=1;i<sz(t);i++)
        {
            while(x>=0&&t[x+1]!=t[i]) x=p[x];
            p[i]=++x;
        }
        c2[0]=c1[0];
        c2[1]=c1[1];
        for(int i=1;i<=p[sz(t)-1];i++) c2[t[i]-'0']--;
        if(c[0]>=c1[0]&&c[1]>=c1[1])
        {
            for(int i=1;i<sz(t);i++) cout<<t[i];
            c[0]-=c1[0];
            c[1]-=c1[1];
            while(c[0]>=c2[0]&&c[1]>=c2[1])
            {
                for(int i=p[sz(t)-1]+1;i<sz(t);i++) cout<<t[i];
                c[0]-=c2[0];
                c[1]-=c2[1];
            }
        }
        while(c[0]--) cout<<'0';
        while(c[1]--) cout<<'1';
    }

    return 0;
}