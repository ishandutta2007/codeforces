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

int querry(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
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
        int n;
        cin>>n;
        int l=1,r=n,sr,ans;
        int mx=querry(1,n);
        if(n==2)
        {
            if(mx==1) cout<<"! "<<2<<endl;
            else cout<<"! "<<1<<endl;
            return 0;
        }
        if(mx==1||querry(1,mx)!=mx)
        {
            l=mx+1;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(querry(1,sr)==mx)
                {
                    ans=sr;
                    r=sr-1;
                }
                else l=sr+1;
            }
            cout<<"! "<<ans<<endl;
        }
        else
        {
            r=mx-1;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(querry(sr,n)==mx)
                {
                    ans=sr;
                    l=sr+1;
                }
                else r=sr-1;
            }
            cout<<"! "<<ans<<endl;
        }
    }
    return 0;
}