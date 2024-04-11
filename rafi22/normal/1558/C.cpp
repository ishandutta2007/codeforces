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

int p[3000];

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
        cin>>n;
        bool nie=0;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            if(i%2!=p[i]%2) nie=1;
        }
        if(nie)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<int>ans;
        for(int i=n;i-1>0;i-=2)
        {
            for(int j=1;j<=i;j++)
            {
                if(p[j]==i)
                {
                    ans.pb(j);
                    reverse(p+1,p+j+1);
                }
            }
            for(int j=1;j<=i;j++)
            {
                if(p[j]==i-1)
                {
                    ans.pb(j-1);
                    reverse(p+1,p+j);
                    ans.pb(j+1);
                    reverse(p+1,p+j+2);
                    ans.pb(3);
                    reverse(p+1,p+4);
                }
            }
            ans.pb(i);
            reverse(p+1,p+i+1);
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }


    return 0;
}