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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int x=inf,y=-inf;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i>0) ans+=s[i]-'0';
            if(i<n-1) ans+=(s[i]-'0')*10;
            if(s[i]=='1'&&x==inf) x=i;
            if(s[i]=='1') y=i;
        }
        if(n==2)
        {
            if(k>=1&&s[0]=='1'&&s[1]=='0') ans-=9;
            cout<<ans<<endl;
            continue;
        }
        if(x!=0&&y!=n-1&&x!=y&&n-1-y+x<=k) ans-=11;
        else if(y!=n-1&&n-1-y<=k)
        {
            if(y==0) ans-=9;
            else ans-=10;
        }
        else if(x!=0&&x!=n-1&&x<=k) ans--;
        cout<<ans<<endl;
    }

    return 0;
}