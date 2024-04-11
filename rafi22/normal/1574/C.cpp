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

const bool multi=0;


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
        int n,m,sum=0;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(all(a));
        cin>>m;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            int xd=lower_bound(all(a),x)-a.begin();
            int c;
            if(xd==n) c=0;
            else c=a[xd];
            int ans=0,ans1=inf;
            if(c==0)
            {
                ans+=x-a[n-1];
                c=a[n-1];
            }
            ans+=max(0LL,y-(sum-c));
            if(xd>0)
            {
                int c1=a[xd-1];
                ans1=0;
                ans1+=x-c1;
                ans1+=max(0LL,y-(sum-c1));
            }
            cout<<min(ans1,ans)<<endl;
        }
    }

    return 0;
}