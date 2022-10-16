#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int k; cin>>k;
    while(k--)
    {
        vector<int> a;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x; a.push_back(x);
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int res=0;
        for(int i=0;i<n;i++)
        {
            int ile=min(i+1,a[i]);
            res=max(res,ile);
        }
        cout<<res<<endl;
    }
    return 0;
}