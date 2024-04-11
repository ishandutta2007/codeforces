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

bool was[300];

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
        memset(was,0,sizeof was);
        string s;
        cin>>s;
        int x=sz(s);
        for(int i=sz(s)-1;i>=0;i--)
        {
            if(!was[s[i]]) x=i;
            was[s[i]]=1;
        }
        for(int i=x;i<sz(s);i++) cout<<s[i];
        cout<<endl;
    }

    return 0;
}