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
        int n,a,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a%2==0) cout<<a/2<<endl;
            else
            {
                cnt++;
                if(cnt%2)
                {
                    if(a>0) cout<<a/2+1<<endl;
                    else cout<<a/2<<endl;
                }
                else
                {
                    if(a>0) cout<<a/2<<endl;
                    else cout<<a/2-1<<endl;
                }
            }
        }
    }

    return 0;
}