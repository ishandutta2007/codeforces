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

const bool multi=1;

int rep[1000007];
bool p[1000007];
map<int,int> mapa;
set<int> s;

signed main()
{
    for(int i=1;i<=1000000;i++) rep[i]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(!p[i])
        {
            rep[i]=i;
            for(int j=2*i;j<=1000000;j+=i)
            {
                p[j]=1;
                int x=0,y=j;
                while(y%i==0)
                {
                    x++;
                    y/=i;
                }
                if(x%2) rep[j]*=i;
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
        int n,a,q,one=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            mapa[rep[a]]++;
            if(rep[a]==1) one++;
            s.insert(rep[a]);
           // cout<<rep[a]<<" ";
        }
      //  cout<<endl;
        cin>>q;
        int mx=0,sum=0;
        for(auto x:s)
        {
            mx=max(mx,mapa[x]);
            if(x!=1&&mapa[x]%2==0) sum+=mapa[x];
        }
       // cout<<mx<<" "<<sum<<endl;
        while(q--)
        {
            cin>>a;
            if(a) cout<<max(mx,sum+one)<<endl;
            else cout<<mx<<endl;
        }
        mapa.clear();
        s.clear();
    }

    return 0;
}