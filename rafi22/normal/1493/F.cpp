#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int N,M;

bool ask(int a,int b,int x1,int y1,int x2,int y2)
{
    cout<<"? "<<a<<" "<<b<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    bool r;
    cin>>r;
    return r;
}

bool check1(int n,int k)
{
    int x=n/k,poc=1;
    while(x>1)
    {
        if(!ask(x/2*k,M,poc,1,poc+x/2*k,1)) return 0;
        poc+=x/2*k;
        x=x/2+x%2;
    }
    return 1;
}
bool check2(int m,int k)
{
    int x=m/k,poc=1;
    while(x>1)
    {
        if(!ask(N,x/2*k,1,poc,1,poc+x/2*k)) return 0;
        poc+=x/2*k;
        x=x/2+x%2;
    }
    return 1;
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
        int n,m;
        cin>>n>>m;
        N=n;
        M=m;
        vector<int>d1,d2,g1,b1,g2,b2,r1,r2;
        for(int i=1;i<n;i++) if(n%i==0) d1.pb(i);
        for(int i=1;i<m;i++) if(m%i==0) d2.pb(i);
        reverse(d1.begin(),d1.end());
        reverse(d2.begin(),d2.end());
        for(auto d:d1)
        {
            bool bad=0;
            if(n%d!=0) bad=1;
            for(auto x:b1) if(x%d==0) bad=1;
            if(bad)
            {
                r1.pb(d);
                continue;
            }
            if(check1(n,d))
            {
                n=d;
                g1.pb(d);
            }
            else b1.pb(d);
        }
        reverse(r1.begin(),r1.end());
        for(auto d:r1)
        {
            for(auto x:g1)
            {
                if(d%x==0)
                {
                    g1.pb(d);
                    break;
                }
            }
        }
        for(auto d:d2)
        {
            bool bad=0;
            if(m%d!=0) bad=1;
            for(auto x:b2) if(x%d==0) bad=1;
            if(bad)
            {
                r2.pb(d);
                continue;
            }
            if(check2(m,d))
            {
                m=d;
                g2.pb(d);
            }
            else b2.pb(d);
        }
        reverse(r2.begin(),r2.end());
        for(auto d:r2)
        {
            for(auto x:g2)
            {
                if(d%x==0)
                {
                    g2.pb(d);
                    break;
                }
            }
        }
        cout<<"! "<<(sz(g1)+1)*(sz(g2)+1)<<endl;
    }

    return 0;
}