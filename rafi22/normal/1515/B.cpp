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

map<int,int>is;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=100000;i++)
    {
        if(2*i*i>1000000000) break;
        is[2*i*i]=1;
    }
    for(int i=1;i<=100000;i++)
    {
        if(4*i*i>1000000000) break;
        is[4*i*i]=1;
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        if(is[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}