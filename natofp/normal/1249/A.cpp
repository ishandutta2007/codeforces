#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        int n; cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            a.push_back(x);
        }
        bool ok = true;
        sort(a.begin(),a.end());
        for(int i=1;i<a.size();i++)
        {
            if(a[i]==a[i-1]+1) ok = false;
        }
        if(ok==true) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}