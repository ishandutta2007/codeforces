#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int calc(vector<int> v,int i)
{
    if(i==-1) return 0;
    vector<int>v0,v1;
    for(auto x:v)
    {
        if((x&(1<<i))) v1.pb(x);
        else v0.pb(x);
    }
    if(v1.size()==0) return calc(v0,i-1);
    if(v0.size()==0) return calc(v1,i-1);
    return max(calc(v0,i-1),calc(v1,i-1))+1;
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
        int n,a;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.pb(a);
        }
        cout<<n-1-calc(v,31);
    }

    return 0;
}