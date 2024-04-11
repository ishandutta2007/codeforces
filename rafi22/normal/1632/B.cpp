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
        int n,c;
        cin>>n;
        for(int i=18;i>=0;i--)
        {
            if(n-1>=1<<i)
            {
                c=1<<i;
                break;
            }
        }
        for(int i=1;i<c;i++) cout<<i<<" ";
        cout<<0<<" ";
        for(int i=c;i<n;i++) cout<<i<<" ";
        cout<<endl;
    }


    return 0;
}