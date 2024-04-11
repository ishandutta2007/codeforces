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
vector<int>vec[1000007];
map<int,int>mapa;
map<int,int>odw;

int calc(int m)
{
    if(odw[m]) return odw[m]-1;
    vector<int>v;
    v.pb(inf);
    int m1=m,m2=0;
    for(int i=0;i<=30;i++)
    {
        if((m1>>(i+1))|m2!=m) v.pb(calc((m1>>(i+1))|m2));
        if((m&(1<<i)))
        {
            m1-=(1<<i);
            m2+=(1<<i);
        }
    }
    int it=0;
    sort(v.begin(),v.end());
    for(int i=0;i<sz(v)+7;i++)
    {
        bool b=0;
        while(it<sz(v)&&v[it]==i)
        {
            b=1;
            it++;
        }
        if(!b)
        {
            odw[m]=i+1;
            return i;
        }
    }
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
        int n,a,it=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            int k=2,sq=sqrt(a);
            while(a>1&&k<=sq)
            {
                int c=0;
                while(a%k==0)
                {
                    c++;
                    a/=k;
                }
                if(c)
                {
                    if(mapa[k]==0) mapa[k]=++it;
                    vec[mapa[k]].pb(c);
                }
                k++;
            }
            if(a>1)
            {
                if(mapa[a]==0) mapa[a]=++it;
                vec[mapa[a]].pb(1);
            }
        }
        int ans=0;
        for(int i=1;i<=it;i++)
        {
            int m=0;
            for(auto x:vec[i]) m|=(1<<(x-1));
            ans^=calc(m);
        }
        if(ans) cout<<"Mojtaba";
        else cout<<"Arpa";
    }

    return 0;
}