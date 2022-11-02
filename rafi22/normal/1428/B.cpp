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
        bool a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='<') a=1;
            if(str[i]=='>') b=1;
        }
        //cout<<a<<" "<<b<<endl;
        if(str[n-1]=='-') ans++;
        else if(str[0]=='-') ans++;
        else
        {
            if(str[n-1]=='<'&&!b) ans++;
            else if(str[0]=='>'&&!a) ans++;
        }
        for(int i=1;i<n;i++)
        {
            if(str[i-1]=='-') ans++;
            else if(str[i]=='-') ans++;
            else
            {
                if(str[i-1]=='<'&&!b) ans++;
                else if(str[i]=='>'&&!a) ans++;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}