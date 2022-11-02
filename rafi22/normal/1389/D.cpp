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
int pref[300007];

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
        int n,k,l,p,L,P,ans=0;
        cin>>n>>k>>l>>p>>L>>P;
        if(L<l) swap(l,L);
        if(p>P) swap(p,P);
        k-=max((int)0,n*(p-L));
        if(k<1)
        {
            cout<<0<<endl;
            continue;
        }
        int x=min((P-l)-max((int)0,(p-L)),k),y=max((int)0,L-p);
        ans+=x+y;
        k-=x;
       // cout<<x<<" "<<y<<endl;
        for(int i=1;i<n;i++)
        {
            x=min((P-l)-max((int)0,(p-L)),k);
            if(k<1) break;
            if(y>=x) break;
            ans+=y+x;
            k-=x;
        }
        ans+=2*k;
        cout<<ans<<endl;
    }

    return 0;
}