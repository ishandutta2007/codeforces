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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int last=-1;
        for(int i=0;i<sz(s);i++)
        {
            if(s[i]=='0')
            {
                if(last==1)
                {
                    cout<<0;
                    last=0;
                }
                else
                {
                    cout<<1;
                    last=1;
                }
            }
            else
            {
                if(last==2)
                {
                    cout<<0;
                    last=1;
                }
                else
                {
                    cout<<1;
                    last=2;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}