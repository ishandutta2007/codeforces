#include <bits/stdc++.h>

#define int long long
#define double long double
#define ll long long
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

int a[200007];
set<int>p;

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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]%2==1) ans++;
        }
        for(int j=0;j<8;j++)
        {
            int i=rand()*rand()%n+1;
            for(int l=max(1LL,a[i]-8);l<=a[i]+8;l++)
            {
                int x=l,k=2;
                while(k<=sqrt(l))
                {
                    if(x%k==0)
                    {
                        p.insert(k);
                        while(x%k==0) x/=k;
                    }
                    k++;
                }
                if(x>1) p.insert(x);
            }
        }
        if(sz(p)>2000) return 2137;
        for(auto d:p)
        {
            int act=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]<d) act+=d-a[i];
                else act+=min(a[i]%d,d-a[i]%d);
            }
            ans=min(ans,act);
        }
        cout<<ans;
    }

    return 0;
}