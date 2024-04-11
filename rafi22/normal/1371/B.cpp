#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

vector <int> ans;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,cnt;
        cin>>a>>b;
        cnt=min(a-1,b);
        cout<<cnt*(cnt+1)/2+(a<=b)<<endl;
    }

    return 0;
}