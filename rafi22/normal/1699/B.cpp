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
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i%4==0||i%4==3)
                {
                    if(j%4==0||j%4==3) cout<<1<<" ";
                    else cout<<0<<" ";
                }
                else
                {
                    if(j%4==1||j%4==2) cout<<1<<" ";
                    else cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}