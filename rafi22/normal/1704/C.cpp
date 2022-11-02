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

const int N=100007;

int a[N];

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
        for(int i=0;i<m;i++) cin>>a[i];
        sort(a,a+m);
        vector<int>V;
        for(int i=1;i<m;i++) V.pb(a[i]-a[i-1]-1);
        V.pb(n-a[m-1]+a[0]-1);
        sort(all(V),greater<int>());
        int ans=0,c=0;
        for(int i=0;i<m;i++)
        {
            int l=max(0LL,V[i]-2*c);
            if(l<=2)
            {
                if(l>0)
                {
                    ans++;
                    c++;
                }
            }
            else
            {
                ans+=l-1;
                c+=2;
            }
        }
        cout<<n-ans<<endl;
    }

    return 0;
}