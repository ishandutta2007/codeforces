#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char x; cin>>x;
        if(x=='8') ans++;
    }
    cout<<min(ans,n/11);
    return 0;
}