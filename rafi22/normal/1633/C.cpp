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
        int hc,dc,hm,dm,k,w,a;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;
        bool ans=0;
        for(int i=0;i<=k;i++)
        {
            int x=(hc+a*i)/dm+min(1LL,(hc+a*i)%dm);
            int y=hm/(dc+(k-i)*w)+min(1LL,hm%(dc+(k-i)*w));
            if(y<=x) ans=1;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}