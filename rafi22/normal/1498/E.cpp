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

pair<int,int> k[507];

bool ask(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    string s;
    cin>>s;
    if(s=="Yes") return 1;
    return 0;
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
        int n,a=0,b=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>k[i].st;
            k[i].nd=i;
        }
        sort(k+1,k+n+1);
        vector<pair<int,pair<int,int>>>vec;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                vec.pb({abs(k[i].st-k[j].st),{k[i].nd,k[j].nd}});
            }
        }
        sort(vec.begin(),vec.end(),greater<pair<int,pair<int,int>>>());
        for(auto x:vec)
        {
            if(ask(x.nd.nd,x.nd.st))
            {
                cout<<"! "<<x.nd.nd<<" "<<x.nd.st<<endl;
                return 0;
            }
        }
        cout<<"! "<<0<<" "<<0<<endl;
    }

    return 0;
}