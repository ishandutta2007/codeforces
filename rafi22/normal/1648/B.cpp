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
bool is[1000007];
int P[1000007];

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
        int n,c;
        cin>>n>>c;
        bool dwa=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(is[a[i]]) dwa=1;
            is[a[i]]=1;
        }
        for(int i=1;i<=c;i++) P[i]=P[i-1]+is[i];
        bool ans=1;
        if(dwa&&!is[1]) ans=0;
        for(int i=1;i<=c;i++)
        {
            if(!is[i]) continue;
            for(int j=i;j<=c;j+=i)
            {
                int X=P[min(c,j+i-1)]-P[max(0LL,j-1)];
                if(X>0&&!is[j/i]) ans=0;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        for(int i=1;i<=c;i++)
        {
            is[i]=0;
            P[i]=0;
        }
    }

    return 0;
}