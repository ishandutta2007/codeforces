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

const bool multi=1;

int ask(int t,int i,int j,int x)
{
    cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
    int r;
    cin>>r;
    return r;
}

int ans[10007];

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
        int one=-1;
        for(int i=1;i<n;i+=2)
        {
            int xd=ask(2,i,i+1,1);
            if(xd==1)
            {
                one=i;
                break;
            }
            if(xd==2)
            {
                if(ask(2,i+1,i,1)==1)
                {
                    one=i+1;
                    break;
                }
            }
        }
        if(one==-1) one=n;
        ans[one]=1;
        for(int i=1;i<=n;i++)
        {
            if(i==one) continue;
            ans[i]=ask(1,one,i,n-1);
        }
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}