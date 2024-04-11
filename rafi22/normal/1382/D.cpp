#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

bool DP[4007];
int tab[4007];
vector <int> v;

void clean(int n)
{
    v.clear();
    for(int i=0;i<=2*n;i++)
    {
        DP[i]=0;
    }
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
        int n;
        cin>>n;
        for(int i=1;i<=2*n;i++) cin>>tab[i];
        int mx=tab[1],last=1;
        for(int i=2;i<=2*n;i++)
        {
            if(tab[i]>mx)
            {
                v.pb(i-last);
                last=i;
                mx=tab[i];
            }
        }
        v.pb(2*n+1-last);
        DP[0]=1;
        for(int i=0;i<v.size();i++)
        {
            for(int j=n;j>=0;j--)
            {
                if(DP[j]&&j+v[i]<=n) DP[j+v[i]]=1;
                //cout<<DP[j]<<" ";
            }
           // cout<<endl;
        }
        if(DP[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        clean(n);
    }

    return 0;
}