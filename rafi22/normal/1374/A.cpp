#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        long long x,y,n,ans;
        cin>>x>>y>>n;
        ans=y+(n-y)-(n-y)%x;
        cout<<ans<<endl;
    }
    return 0;
}