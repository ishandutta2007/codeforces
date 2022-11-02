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

int tab[300007];
int pref[300007];

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
        string str;
        cin>>str;
        int n=str.size();
        int ans=0;
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(i==j)
                {
                    int act=0;
                    for(int l=0;l<n;l++) if(str[l]==i+48) act++;
                    ans=max(ans,act);
                }
                else
                {
                    bool b=0;
                    int act=0;
                    for(int l=0; l<n; l++)
                    {
                        if(!b)
                        {
                            if(str[l]==i+48) b=1;
                        }
                        else
                        {
                            if(str[l]==j+48)
                            {
                                b=0;
                                act++;
                            }
                        }
                    }
                    ans=max(ans,2*act);
                }
            }
        }
        cout<<n-ans<<endl;
    }

    return 0;
}