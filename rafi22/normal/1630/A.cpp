#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

pair<int,int>get(int a,int b)
{
    return {min(a,b),max(a,b)};
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
        int n,k;
        cin>>n>>k;
        set<pair<int,int>>P;
        for(int i=0;i<n/2;i++) P.insert({i,n-1-i});
        if(k!=n-1)
        {
            P.erase(get(0,n-1));
            P.erase(get(k,n-1-k));
            P.insert({k,n-1});
            P.insert({0,n-1-k});
        }
        else
        {
            if(n==4)
            {
                cout<<-1<<endl;
                continue;
            }
            P.erase(get(0,n-1));
            P.erase(get(1,n-2));
            P.erase(get(n/2-1,n/2));
            P.insert({0,1});
            P.insert({n/2-1,n-1});
            P.insert({n/2,n-2});
        }
        for(auto x:P) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}