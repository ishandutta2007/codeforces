#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x; a.push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x; b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<endl;

}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}