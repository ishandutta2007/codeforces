#include <bits/stdc++.h>

//#define int long long
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
int inf=1000000007;
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
        cin>>n;
        vector<int>a(n+2);
        a[0]=-inf;
        for(int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=inf;
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i-1]) continue;
            int c=1;
            for(int j=i+1;j<=n;)
            {
                c++;
                int nj=lower_bound(all(a),2*a[j]-a[i])-a.begin();
                if(j>=nj) j++;
                else j=nj;
            }
            ans=min(ans,n-c);
        }
        cout<<ans<<endl;
    }

    return 0;
}