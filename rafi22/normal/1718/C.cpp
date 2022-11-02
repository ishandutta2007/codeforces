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
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

const int N=200007;

ll a[N];
ll sum[20][N];

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
        int n,q;
        cin>>n>>q;
        vector<int>V;
        V.pb(1);
        int x=n;
        for(int k=2;k<n;k++)
        {
            if(x%k==0) V.pb(n/k);
            while(x%k==0) x/=k;
        }
        for(int i=0;i<sz(V);i++)
        {
            for(int j=0;j<V[i];j++) sum[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            for(int j=0;j<sz(V);j++) sum[j][i%V[j]]+=a[i];
        }
        multiset<ll>S;
        for(int i=0;i<sz(V);i++)
        {
            for(int j=0;j<V[i];j++)
            {
                S.insert(sum[i][j]*(ll)(V[i]));
            }
        }
        cout<<*--S.end()<<endl;
        while(q--)
        {
            int i,x;
            cin>>i>>x;
            for(int j=0;j<sz(V);j++)
            {
                S.erase(S.find(sum[j][i%V[j]]*(ll)(V[j])));
                sum[j][i%V[j]]-=a[i];
            }
            a[i]=x;
            for(int j=0;j<sz(V);j++)
            {
                sum[j][i%V[j]]+=a[i];
                S.insert(sum[j][i%V[j]]*(ll)(V[j]));
            }
            cout<<*--S.end()<<endl;
        }
    }

    return 0;
}