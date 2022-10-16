#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<int> a;

void solve()
{
    int n; cin>>n;
    a.clear();
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x; a.push_back(x);
    }
    for(int i=1;i<n;i++)
    {
        if(abs(a[i]-a[i-1])>=2)
        {
            cout<<"YES"<<"\n";
            cout<<i<<" "<<i+1<<"\n";
            return ;
        }
    }
    cout<<"NO"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}