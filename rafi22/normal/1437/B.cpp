#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int n,ans=0;
        cin>>n;
        string str;
        cin>>str;
        vector <int> bad;
        for(int i=1;i<n;i++)
        {
            if(str[i]!=str[0]&&i%2==0) bad.pb(i);
            if(str[i]==str[0]&&i%2) bad.pb(i);
        }
        if(bad.size()>0) ans++;
        for(int i=1;i<bad.size();i++)
        {
            if(bad[i]!=bad[i-1]+1) ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}