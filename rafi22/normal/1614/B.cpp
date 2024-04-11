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

int a[200007];
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
        vector<pair<int,int>>V(n);
        for(int i=1;i<=n;i++)
        {
            cin>>V[i-1].st;
            V[i-1].nd=i;
        }
        sort(all(V),greater<pair<int,int>>());
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=2*(i/2+1)*V[i].st;
            if(i%2) ans[V[i].nd]=-(i/2+1);
            else ans[V[i].nd]=i/2+1;
        }
        cout<<res<<endl;
        for(int i=0;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}