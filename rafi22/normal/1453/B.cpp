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

int tab[200007];

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
        int n,ans=0,opt=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=n;i>1;i--) ans+=abs(tab[i]-tab[i-1]);
        opt=abs(tab[1]-tab[2]);
        for(int i=2;i<n;i++)
        {
            int p=abs(tab[i]-tab[i-1])+abs(tab[i+1]-tab[i]);
            int x=(tab[i-1]+tab[i+1])/2;
            int p1=abs(x-tab[i-1])+abs(tab[i+1]-x);
            opt=max(opt,p-p1);
        }
        opt=max(opt,abs(tab[n-1]-tab[n]));
        cout<<ans-opt<<endl;
    }

    return 0;
}