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

int pref[200007];
int silnia[25];

signed main()
{
    silnia[0]=1;
    for(int i=1;i<20;i++) silnia[i]=silnia[i-1]*i;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,q,k=1,s;
        cin>>n>>q;
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+i;
        s=min((int)15,n);
        while(q--)
        {
            int t,l,r;
            cin>>t;
            if(t==1)
            {
                cin>>l>>r;
                cout<<pref[r]-pref[l-1]<<endl;
            }
            else
            {
                cin>>l;
                k+=l;
                bool taken[21];
                int perm[21];
                for(int i=0;i<=s;i++) taken[i]=0;
                int act=0;
                for(int i=1;i<=s;i++)
                {
                    for(int j=1;j<=s;j++)
                    {
                        if(taken[j]) continue;
                        //cout<<silnia[s-i]<<endl;
                        if(act+silnia[s-i]>=k)
                        {
                            taken[j]=1;
                            perm[i]=n-s+j;
                            break;
                        }
                        act+=silnia[s-i];
                    }
                }

                for(int i=n-s+1;i<=n;i++) pref[i]=pref[i-1]+perm[i-(n-s)];
            }
        }
    }

    return 0;
}