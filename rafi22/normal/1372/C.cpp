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
        int n,res=inf,ans=0;
        cin>>n;
        int s[n];
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            s[i]=tab[i];
        }
        sort(s,s+n);
        bool is=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==tab[i])
            {
                is=0;
            }
            else
            {
                if(!is) ans++;
                is=1;
            }
        }
        cout<<min((int)2,ans)<<endl;
    }

    return 0;
}