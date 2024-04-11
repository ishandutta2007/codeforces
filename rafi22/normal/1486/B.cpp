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

int x[1007];
int y[1007];

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
        vector<int>mx,my;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i];
            mx.pb(x[i]);
            my.pb(y[i]);
        }
        sort(mx.begin(),mx.end());
        sort(my.begin(),my.end());
        if(n%2==1) cout<<1<<endl;
        else cout<<(mx[n/2]-mx[n/2-1]+1)*(my[n/2]-my[n/2-1]+1)<<endl;

    }
    return 0;
}