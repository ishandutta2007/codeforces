#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        vector<int> a;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x; a.push_back(x);
        }
        sort(a.begin(),a.end());
        int res=n-2;
        res=min(res,a[n-2]-1);
        cout<<max(res,0)<<endl;

    }
    return 0;
}