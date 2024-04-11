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

int a[1000007];
vector<int>V[1000007];

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
        int n,m,sum=0,x;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int k=0;
        while(m--)
        {
            cin>>x;
            k=__gcd(k,x);
        }
        for(int i=0;i<k;i++) V[i].clear();
        for(int i=1;i<=n;i++) V[i%k].pb(a[i]);
        int c[2]={0,0};
        for(int i=0;i<k;i++)
        {
            sort(all(V[i]));
            int xd=0;
            int b[2]={-inf,-inf};
            for(int j=0;;j++)
            {
                b[j%2]=max(b[j%2],xd);
                if(j==sz(V[i])) break;
                xd+=-2*V[i][j];
            }
            c[0]+=b[0];
            c[1]+=b[1];
        }
        cout<<sum+max(c[0],c[1])<<endl;
    }

    return 0;
}