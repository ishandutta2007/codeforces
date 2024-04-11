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

const bool multi=1;


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
        int n,sum=0,a;
        vector <int> v;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            sum+=a;
            v.pb(a);
        }
        if(sum==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(sum>0)
        {
            cout<<"YES"<<endl;
            sort(v.begin(),v.end(),greater<int>());
            for(int i=0;i<n;i++) cout<<v[i]<<" ";
            cout<<endl;
        }
        else
        {
             cout<<"YES"<<endl;
             sort(v.begin(),v.end());
             for(int i=0;i<n;i++) cout<<v[i]<<" ";
             cout<<endl;
        }
    }

    return 0;
}