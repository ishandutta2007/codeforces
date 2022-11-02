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

int F(int a)
{ return a*(a+1)/2;}

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
        vector <int> ans;
        for(int i=1;i<=n;i*=2)
        {
            ans.pb(i);
            n-=i;
        }
        if(n>0) ans.pb(n);
        sort(ans.begin(),ans.end());
        cout<<ans.size()-1<<endl;
        for(int i=1;i<ans.size();i++) cout<<ans[i]-ans[i-1]<<" ";
        cout<<endl;
    }

    return 0;
}