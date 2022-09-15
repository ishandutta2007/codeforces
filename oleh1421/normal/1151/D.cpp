#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        v.push_back({b-a,{a,b}});
    }
    sort(v.begin(),v.end());
    int sum=0ll;
    for (int i=0;i<n;i++){
        sum+=v[i].second.first*i+v[i].second.second*(n-i-1ll);
    }
    cout<<sum;
    return 0;
}
//2 6 -2 -6  2