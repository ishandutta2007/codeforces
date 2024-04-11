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

int a[200007];

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
        int mn=inf,p=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<mn)
            {
                mn=a[i];
                p=i;
            }
        }
        if(p!=1)
        {
            cout<<n<<endl;
            cout<<p<<" "<<1<<" "<<mn<<" "<<mn<<endl;
        }
        else cout<<n-1<<endl;
        for(int i=2;i<=n;i++) cout<<1<<" "<<i<<" "<<mn<<" "<<mn+i-1<<endl;
    }

    return 0;
}