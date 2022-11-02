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
        int n,m,k,x;
        cin>>n>>m>>k;
        int cn=0,xn=0,cm=0,xm=0;
        for(int i=1;i<=k;i++)
        {
            cin>>x;
            if(x/n>1)
            {
                cn+=x/n;
                if(x/n>2) xn=1;
            }
            if(x/m>1)
            {
                cm+=x/m;
                if(x/m>2) xm=1;
            }
        }
        if((cn>=m&&!(m%2!=cn%2&&!xn))||(cm>=n&&!(n%2!=cm%2&&!xm))) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}