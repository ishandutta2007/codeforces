#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n,m;
        cin>>a>>b>>n>>m;
        if(b>a) swap(a,b);
        int x=min(n,(a-b));
        n-=x;
        a-=x;
        if(b<m) cout<<"NO"<<endl;
        else if(a+b<n+m) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}