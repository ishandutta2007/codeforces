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
        int n;
        string s;
        cin>>n>>s;
        s='#'+s;
        if(n>1&&s[1]==s[2])
        {
            cout<<s[1]<<s[1]<<endl;
            continue;
        }
        int k,mn=inf;
        for(int i=1;i<=n;i++)
        {
            if(s[i]<=mn)
            {
                k=i;
                mn=s[i];
            }
            if(i!=n&&s[i]<s[i+1]) break;
        }
        for(int i=1;i<=k;i++) cout<<s[i];
        for(int i=k;i>0;i--) cout<<s[i];
        cout<<endl;
    }

    return 0;
}