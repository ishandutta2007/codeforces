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

int s[100007];

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
        for(int i=1;i<=k;i++) cin>>s[i];
        bool ok=1;
        int mn=inf;
        for(int i=k-1;i>0;i--)
        {
            int c=s[i+1]-s[i];
            if(c>mn) ok=0;
            mn=c;
        }
        if(mn!=inf&&(n-k+1)*mn<s[1]) ok=0;
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}