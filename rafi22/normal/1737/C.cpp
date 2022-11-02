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
        int n;
        cin>>n;
        int r1,c1,r2,c2,r3,c3;
        cin>>r1>>c1>>r2>>c2>>r3>>c3;
        int X,Y,x,y;
        if(r1==r2) X=r1;
        if(r1==r3) X=r1;
        if(r2==r3) X=r2;
        if(c1==c2) Y=c1;
        if(c1==c3) Y=c1;
        if(c2==c3) Y=c2;
        cin>>x>>y;
        if((X==1&&Y==1))
        {
            if(x==1||y==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if((X==1&&Y==n))
        {
            if(x==1||y==n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if((X==n&&Y==1))
        {
            if(x==n||y==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if((X==n&&Y==n))
        {
            if(x==n||y==n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if(abs(X-x)%2==1&&abs(Y-y)%2==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}