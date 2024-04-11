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

const bool multi=0;

void gg()
{
    cout<<"No";
    exit(0);
}

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
        int a,b,k;
        cin>>a>>b>>k;
        if(k==0)
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<b;i++) cout<<1;
            for(int i=0;i<a;i++) cout<<0;
            cout<<endl;
            for(int i=0;i<b;i++) cout<<1;
            for(int i=0;i<a;i++) cout<<0;
            cout<<endl;
        }
        else
        {
            if(a==0||b==1) gg();
            if(k>=a+b-1) gg();
            vector<bool>r1,r2;
            r1.pb(1);
            r2.pb(1);
            r1.pb(1);
            r2.pb(0);
            b-=2;
            a--;
            for(int i=0;i<k-1;i++)
            {
                if(b)
                {
                    r1.pb(1);
                    r2.pb(1);
                    b--;
                }
                else if(a)
                {
                    r1.pb(0);
                    r2.pb(0);
                    a--;
                }
                else return 2137;
            }
            r1.pb(0);
            r2.pb(1);
            for(int i=0;i<b;i++)
            {
                r1.pb(1);
                r2.pb(1);
            }
            for(int i=0;i<a;i++)
            {
                r1.pb(0);
                r2.pb(0);
            }
            cout<<"Yes"<<endl;
            for(auto x:r1) cout<<x;
            cout<<endl;
            for(auto x:r2) cout<<x;
            cout<<endl;
        }
    }

    return 0;
}