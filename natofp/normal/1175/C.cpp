#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<long long int> a;
    int t; cin>>t;
    while(t--)
    {
        a.clear();
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int x; cin>>x;
            a.push_back(x);
        }
        long long int ans=1e18;
        long long int x=-1;
        for(int i=0;i<n;i++)
        {
            int kon=i+k;
            if(kon>=n) break;
            if(a[kon]-a[i]<ans)
            {
                ans=a[kon]-a[i];
                x=(a[kon]+a[i])/2;
            }
        }
        cout<<x<<endl;

    }
    return 0;
}