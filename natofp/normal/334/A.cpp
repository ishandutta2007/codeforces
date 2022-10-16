#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=(i-1)*n/2+1;j<=i*n/2;j++)
        {
            cout<<j<<" "<<n*n-j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}