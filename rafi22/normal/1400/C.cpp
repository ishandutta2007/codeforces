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
        string w,s;
        cin>>w;
        int x;
        cin>>x;
        for(int i=0;i<sz(w);i++) s+='1';
        for(int i=0;i<sz(w);i++)
        {
            if(w[i]=='0')
            {
                if(i-x>=0) s[i-x]='0';
                if(i+x<sz(w)) s[i+x]='0';
            }
        }
        bool ok=1;
        for(int i=0;i<sz(w);i++)
        {
            if(w[i]=='1')
            {
                bool is=0;
                if(i-x>=0&&s[i-x]=='1') is=1;
                if(i+x<sz(w)&&s[i+x]=='1') is=1;
                if(!is) ok=0;
            }
        }
        if(!ok) cout<<-1<<endl;
        else cout<<s<<endl;
    }
    return 0;
}