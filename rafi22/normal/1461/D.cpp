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

vector<int>a;
map<int,bool>is;

void licz(vector<int>v)
{
    if(sz(v)==0) return ;
    int mini=inf,maxi=0,sum=0;
    for(auto x:v)
    {
        sum+=x;
        mini=min(mini,x);
        maxi=max(maxi,x);
    }
    is[sum]=1;
    vector<int>v1,v2;
    for(auto x:v)
    {
        if(x<=(mini+maxi)/2) v1.pb(x);
        else v2.pb(x);
    }
    if(sz(v1)!=sz(v)) licz(v1);
    if(sz(v2)!=sz(v)) licz(v2);
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
        a.clear();
        is.clear();
        int n,q,x;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            a.pb(x);
        }
        licz(a);
        while(q--)
        {
            int s;
            cin>>s;
            if(is[s]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }

    return 0;
}