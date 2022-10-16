#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
cout<<"YES"<<endl;
    long long a,b;
    cin>>a>>b;
    for(long long int i=a;i<=b;i+=2)
    {
        cout<<i<<" "<<i+1<<endl;
    }
    return 0;
}