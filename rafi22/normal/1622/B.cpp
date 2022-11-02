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

int p[200007];
int ans[200007];

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
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i];
        string s;
        cin>>s;
        s='#'+s;
        vector<pair<int,int>>V,V1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') V.pb({p[i],i});
            else V1.pb({p[i],i});
        }
        sort(all(V));
        sort(all(V1));
        for(int i=0;i<sz(V);i++) ans[V[i].nd]=i+1;
        for(int i=0;i<sz(V1);i++) ans[V1[i].nd]=i+1+sz(V);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}