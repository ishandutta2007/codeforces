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
int ile[200007];

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
        int n,ans=0,mn=1;
        cin>>n;
        for(int i=0;i<n;i++) cin>>tab[i];
        ile[1]=1;
        int it=1;
        while(it<n)
        {
            int c=1;
            it++;
            while(it<n&&tab[it-1]<tab[it])
            {
                c++;
                it++;
            }
            //cout<<c<<endl;
            bool z=0;
            if(ile[mn]==0) mn++;
            ile[mn]--;
            ile[mn+1]+=c;

        }
        for(int i=1;i<=n;i++) if(ile[i]!=0) ans=i;
        for(int i=1;i<=n;i++)
        {
            ile[i]=0;
        }
        cout<<ans-1<<endl;
    }

    return 0;
}