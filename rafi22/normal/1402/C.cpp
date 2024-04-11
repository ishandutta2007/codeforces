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

bool is[200007];

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
        int a,b;
        cin>>a>>b;
        int n=a+b;
        int R=min(n/2,b)+min(n/2+n%2,a);
        int L=max(0LL,n/2-a)+max(0LL,n/2+n%2-b);
        for(int i=R;i>=L;i-=2) is[i]=1;
        swap(a,b);
        R=min(n/2,b)+min(n/2+n%2,a);
        L=max(0LL,n/2-a)+max(0LL,n/2+n%2-b);
        for(int i=R;i>=L;i-=2) is[i]=1;
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            if(is[i]) ans.pb(i);
            is[i]=0;
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }


    return 0;
}