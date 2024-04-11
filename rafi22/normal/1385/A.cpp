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
        int x,y,z,mx,ile=0,n,np;
        cin>>x>>y>>z;
        mx=max(max(x,y),z);
        if(x==mx) ile++;
        else
        {
            np=1;
            n=x;
        }
        if(y==mx) ile++;
        else
        {
            np=2;
            n=y;
        }
        if(z==mx) ile++;
        else
        {
            np=3;
            n=z;
        }
        if(ile<2) cout<<"NO"<<endl;
        else if(ile==3)
        {
            cout<<"YES"<<endl;
            cout<<mx<<" "<<mx<<" "<<mx<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            if(np==1) cout<<n<<" "<<n<<" "<<mx<<endl;
            if(np==2) cout<<n<<" "<<mx<<" "<<n<<endl;
            if(np==3) cout<<mx<<" "<<n<<" "<<n<<endl;
        }
    }

    return 0;
}