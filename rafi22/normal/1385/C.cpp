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
        int n,it,ans=0;
        cin>>n;
        int tab[n+7];
        it=n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        tab[n+1]=0;
        tab[0]=0;
        while(it>0&&tab[it]>=tab[it+1]) it--;
        for(int i=1;i<=it;i++)
        {
            if(tab[i]<tab[i-1]) ans=i;
        }
        cout<<max((int)0,ans-1)<<endl;
    }

    return 0;
}