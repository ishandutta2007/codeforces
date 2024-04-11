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

int last[2];

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
        memset(last,-1,sizeof last);
        int ans=0;
        for(int i=0;i<sz(s);i++)
        {
            if(s[i]!='?') last[(s[i]-'0')^(i%2)]=i;
            ans+=i-min(last[0],last[1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}