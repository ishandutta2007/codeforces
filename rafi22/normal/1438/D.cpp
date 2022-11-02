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

const bool multi=0;

int tab[100007];

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
        int n,x=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
            x^=tab[i];
        }
        if(n%2==0&&x!=0) cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            cout<<n-2-(n%2==0)<<endl;
            for(int i=3;i<=n;i+=2) cout<<i-2<<" "<<i-1<<" "<<i<<endl;
            for(int i=2;i<=n-3;i+=2) cout<<i-1<<" "<<i<<" "<<n<<endl;
        }
    }

    return 0;
}