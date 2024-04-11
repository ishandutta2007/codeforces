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

vector<pair<int,int>> G[40];

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
        int l,r,m=0;
        cin>>l>>r;
        for(int i=2;i<30;i++)
        {
            if((1<<(i-2))>2000000) break;
            for(int j=i-1;j>1;j--)
            {
                G[j].pb({i,(1<<(j-2))});
                m++;
            }
            G[1].pb({i,1});
            m++;
        }
        int x=r-l+1;
        int it=2,prev=0;
        if(x%2!=1) x--;
        while(x>0)
        {
            if(x&1)
            {
                if(it==2) G[1].pb({32,l});
                else G[it].pb({32,prev+l-1});
                prev+=(1<<(it-2));
                m++;
            }
            it++;
            x/=2;
        }
        if((r-l+1)%2!=1)
        {
            G[2].pb({32,r-1});
            m++;
        }
        cout<<"YES"<<endl;
        cout<<32<<" "<<m<<endl;
        for(int i=1;i<=32;i++)
        {
            for(auto j:G[i])
            {
                cout<<i<<" "<<j.st<<" "<<j.nd<<endl;
            }
        }
    }

    return 0;
}