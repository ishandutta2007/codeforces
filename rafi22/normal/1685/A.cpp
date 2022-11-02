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

int b[200007];
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
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if(n%2==1) cout<<"NO"<<endl;
        else
        {
            int it=0;
            for(int i=n/2;i>0;i--)
            {
                b[it]=a[i+n/2];
                b[it+1]=a[i];
                it+=2;
            }
            bool ok=1;
            for(int i=0;i<n;i++)
            {
                if(!((b[i]>b[(i-1+n)%n]&&b[i]>b[(i+1)%n])||(b[i]<b[(i-1+n)%n]&&b[i]<b[(i+1)%n]))) ok=0;
            }
            if(!ok) cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
                for(int i=0;i<n;i++) cout<<b[i]<<" ";
                cout<<endl;
            }
        }
    }

    return 0;
}