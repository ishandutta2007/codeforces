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

const bool multi=0;

int a[100007];
int pref[100007];

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
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]^a[i];
        for(int i=1;i<n;i++)
        {
            bool b=0;
            for(int j=1;j<=n-i;j++)
            {
                int x=pref[j+i]^pref[j-1];
                if(j!=1&&x<a[j-1]) b=1;
                if(j+i!=n&&x>a[j+i+1]) b=1;
            }
            for(int j=1;j<n-i;j++)
            {
                for(int l=j;l<i+1+j;l++)
                {
                    if((pref[l]^pref[j-1])>(pref[i+1+j]^pref[l])) b=1;
                }
            }
            if(b)
            {
                cout<<i;
                return 0;
            }
        }

        cout<<-1;
    }

    return 0;
}