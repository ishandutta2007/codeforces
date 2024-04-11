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
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        bool ok=1;
        int j=0;
        for(int j=m-1;j>0;j--)
        {
            if(s[n-(m-1-j)-1]!=t[j]) ok=0;
        }
        bool is=0;
        for(int i=0;i<=n-m;i++) if(s[i]==t[0]) is=1;
       // cout<<ok<<" "<<is<<endl;
        if(ok&&is) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}