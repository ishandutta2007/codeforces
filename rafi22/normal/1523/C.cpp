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
        int n,a;
        cin>>n;
        vector<int>act;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a==1) act.pb(a);
            else
            {
                while(sz(act)>0)
                {
                    int x=act.back();
                    act.pop_back();
                    if(x+1==a) break;
                }
                act.pb(a);
            }
            for(int j=0;j<sz(act)-1;j++) cout<<act[j]<<'.';
            cout<<act.back()<<endl;
        }
    }

    return 0;
}