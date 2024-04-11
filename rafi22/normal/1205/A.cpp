#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
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
        int n;
        cin>>n;
        if(n%2==0) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            vector<int>V1,V2;
            V1.pb(1);
            bool b=0;
            for(int i=2;i<=2*n;i+=2)
            {
                if(!b)
                {
                    V2.pb(i);
                    if(i<2*n) V2.pb(i+1);
                }
                else
                {
                    V1.pb(i);
                    if(i<2*n) V1.pb(i+1);
                }
                b^=1;
            }
            for(auto x:V1) cout<<x<<" ";
            for(auto x:V2) cout<<x<<" ";
        }
    }

    return 0;
}