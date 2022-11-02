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

const bool multi=0;

int l[100007];
int ans[100007];
void gg()
{
    cout<<-1;
    exit(0);
}

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
        int n,m,sum=0,mx=0,a;
        cin>>n>>m;
        vector<pair<int,int>>v;
        for(int i=1;i<=m;i++)
        {
            cin>>l[i];
            sum+=l[i];
        }
        if(sum<n) gg();
        for(int i=m;i>0;i--)
        {
            mx=max(mx,i+l[i]-1);
            if(mx>n)gg();
            int x=max(0LL,min(n-mx,l[i-1]-1));
            ans[i]+=x;
            mx+=x;
        }
        int act=0;
        for(int i=1;i<=m;i++)
        {
            act+=ans[i];
            cout<<i+act<<" ";
        }


    }

    return 0;
}