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
        string x;
        cin>>x;
        bool is=0;
        for(int i=sz(x)-1;i>0;i--)
        {
            int c=x[i-1]-'0'+x[i]-'0';
            if(c>=10)
            {
                is=1;
                for(int j=0;j<i-1;j++) cout<<x[j];
                if(c>=10) cout<<1;
                cout<<c%10;
                for(int j=i+1;j<sz(x);j++) cout<<x[j];
                cout<<endl;
                break;
            }
        }
        if(is) continue;
        int c=x[0]-'0'+x[1]-'0';
        if(c>=10) cout<<1;
        cout<<c%10;
        for(int j=2;j<sz(x);j++) cout<<x[j];
        cout<<endl;
    }

    return 0;
}