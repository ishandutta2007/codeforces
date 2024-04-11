#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[2]-a[0]<2)
        {
            cout<<0<<endl;
            continue;
        }
        a[2]--;
        a[0]++;
        if(a[1]<a[2]) a[1]++;
        else if(a[1]>a[0]) a[1]--;
        ll sum=0;
        sum+=abs(a[1]-a[2]);
        sum+=abs(a[0]-a[2]);
        sum+=abs(a[0]-a[1]);
        cout<<sum<<endl;
    }
    return 0;
}