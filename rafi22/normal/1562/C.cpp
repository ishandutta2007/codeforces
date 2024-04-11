#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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
        s='#'+s;
        int L1=-1,L2=-1,R1=-1,R2=-1;
        for(int i=n/2+1;i<=n;i++)
        {
            if(s[i]=='0')
            {
                L1=1;
                R1=i;
                L2=1;
                R2=i-1;
            }
        }
        if(L1==-1)
        {
            for(int i=1;i<=n/2;i++)
            {
                if(s[i]=='0')
                {
                    L1=i+1;
                    R1=n;
                    L2=i;
                    R2=n;
                }
            }
        }
        if(L1==-1)
        {
            L1=1;
            R1=n/2;
            R2=n;
            L2=n-n/2+1;
        }
        cout<<L1<<" "<<R1<<" "<<L2<<" "<<R2<<endl;
    }

    return 0;
}