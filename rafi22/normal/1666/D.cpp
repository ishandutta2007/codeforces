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

bool ban[300];

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
        memset(ban,0,sizeof ban);
        string s,t;
        cin>>s>>t;
        bool ok=1;
        int it=sz(s)-1;
        for(int i=sz(t)-1;i>=0;i--)
        {
            if(ban[t[i]])
            {
                ok=0;
                break;
            }
            while(it>=0&&s[it]!=t[i])
            {
                ban[s[it]]=1;
                it--;
            }
            if(it<0)
            {
                ok=0;
                break;
            }
            it--;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}