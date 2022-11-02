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

int tab[200007];
int ile[35];

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
        for(int i=0;i<=33;i++) ile[i]=0;
        int n,a,mini=inf,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            int pot=1,cnt=0;
            ans+=ile[(int)log2(tab[i])];
            ile[(int)log2(tab[i])]++;
        }
        cout<<ans<<endl;
    }

    return 0;
}