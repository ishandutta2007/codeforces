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
int tab[300007];

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
        int sub=0;
        bool ok=1;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=2;i<n;i++)
        {
            if(sub>tab[i]) ok=0;
            if(tab[i]>tab[i-1])
            {
                sub+=tab[i]-tab[i-1];
            }
        }
        if(sub>tab[n]) ok=0;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}