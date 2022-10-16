#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int q; cin>>q;
    vector<int> a;
    while(q--)
    {
        int n; cin>>n;
        int k; cin>>k;
        a.clear();
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int ile=a[n-1]-a[0];
        if(ile>2*k)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            cout<<a[0]+k<<endl;
            continue;
        }
    }
    return 0;
}