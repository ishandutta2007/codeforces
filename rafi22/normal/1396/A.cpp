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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        cout<<1<<" "<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<-n*tab[i]<<" ";
            tab[i]-=n*tab[i];
        }
        cout<<endl;
        if(n!=1)
        {
            cout<<1<<" "<<n-1<<endl;
            for(int i=1; i<=n-1; i++)
            {
                cout<<-tab[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<1<<" "<<1<<endl<<0<<endl;
        cout<<n<<" "<<n<<endl;
        cout<<-tab[n]<<endl;
    }

    return 0;
}