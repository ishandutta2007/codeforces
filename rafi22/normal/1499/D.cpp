#include <bits/stdc++.h>

//#define int long long
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

int ile[20000007];
bool p[20000007];


signed main()
{
    for(int i=2;i<=20000000;i++)
    {
        if(!p[i])
        {
            ile[i]=1;
            for(int j=2*i;j<=20000000;j+=i)
            {
                p[j]=1;
                ile[j]++;
            }
        }
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int c,d,x;
        cin>>c>>d>>x;
        vector<int>div;
        for(int i=1;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {
                div.pb(i);
                if(x/i!=i) div.pb(x/i);
            }
        }
        int ans=0;
        for(auto b:div)
        {
            if((x/b+d)%c==0)
            {
                ans+=(1<<ile[(x/b+d)/c]);
                //cout<<(x/b+d)/c<<endl;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}