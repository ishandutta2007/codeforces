#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(min(abs(x1-x2),abs(y1-y2))==0) cout<<abs(x1-x2)+abs(y1-y2)<<endl;
        else cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
    }

    return 0;
}