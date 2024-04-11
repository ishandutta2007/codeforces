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
        int a,b;
        cin>>a>>b;
        int last=inf,ans=0,best=inf;
        if(b==1)
        {
            b++;
            ans++;
        }
        for(int i=0;i<50;i++)
        {
            int x=b,y=a,cnt=0;
            while(y>0)
            {
                y/=x;
                cnt++;
            }
            best=min(best,ans+cnt);
            b++;
            ans++;
        }
        cout<<best<<endl;
    }

    return 0;
}