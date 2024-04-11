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
        vector<int>V;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int d=max({j-1+i-1,j-1+n-i,m-j+i-1,m-j+n-i});
                V.pb(d);
            }
        }
        sort(all(V));
        for(auto x:V) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}