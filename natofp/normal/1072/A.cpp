#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w,h,k;
    cin>>w>>h>>k;
    int ans=0;
    while(k>0)
    {
        k--;
        ans+=2*w+2*h-4;
        w-=4;
        h-=4;
    }
    cout<<ans;
    return 0;
}