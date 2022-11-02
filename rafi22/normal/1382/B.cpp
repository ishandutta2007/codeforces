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
        int n;
        bool b=0,x=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            if(tab[i]>1)
            {
                x=1;
                if(i%2==1)
                {
                    b=1;
                }
                break;
            }
        }
        if(!x)
        {
            if(n%2==1) b=1;
        }
        if(b) cout<<"First"<<endl;
        else cout<<"Second"<<endl;

    }

    return 0;
}