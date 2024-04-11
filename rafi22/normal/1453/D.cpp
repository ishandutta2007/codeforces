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

const bool multi=1;

int tab[61];
int pot[63];

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
        pot[0]=1;
        for(int i=1;i<63;i++) pot[i]=pot[i-1]*2;
        for(int i=0;i<=60;i++) tab[i]=pot[i+2]-2;
        int k;
        cin>>k;
        if(k%2==1) cout<<-1<<endl;
        else
        {
            vector<bool>ans;
            while(k>0)
            {
                for(int i=60;i>=0;i--)
                {
                    if(tab[i]<=k)
                    {
                        k-=tab[i];
                        ans.pb(1);
                        for(int j=0;j<i;j++) ans.pb(0);
                    }
                }
            }
            cout<<ans.size()<<endl;
            for(auto x:ans) cout<<x<<" ";
            cout<<endl;
        }

    }

    return 0;
}