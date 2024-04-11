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
        int n,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=tab[i];
            mx=max(mx,tab[i]);
        }
        if(n==1) cout<<'T'<<endl;
        else if(n==2)
        {
            if(tab[1]==tab[2]) cout<<"HL"<<endl;
            else cout<<'T'<<endl;
        }
        else if(mx>sum-mx) cout<<'T'<<endl;
        else if(sum%2==0) cout<<"HL"<<endl;
        else cout<<'T'<<endl;
    }
    return 0;
}