#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,k,a,b,c;
    cin>>n>>k;
    a=(n*2)/k+1;
    if ((n*2)%k==0) a--;
    b=(n*5)/k+1;
    if ((n*5)%k==0) b--;
    c=(n*8)/k+1;
    if ((n*8)%k==0) c--;
    cout<<a+b+c;

    return 0;
}