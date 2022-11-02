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

bool ok[107];
bool ok1[107];

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
        memset(ok,0,sizeof ok);
        memset(ok1,0,sizeof ok1);
        string s;
        cin>>s;
        s='#'+s;
        ok[0]=1;
        for(int i=1;i<sz(s);i++) ok[i]=ok[i-1]&&(s[i]=='0'||s[i]!=s[i-1]);
        ok1[sz(s)]=1;
        for(int i=sz(s)-1;i>0;i--) ok1[i]=ok1[i+1]&&(s[i]=='1'||s[i]!=s[i+1]);
        bool ans=0;
        for(int i=0;i<sz(s);i++) if(ok[i]&&ok1[i+1]) ans=1;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}