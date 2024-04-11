#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,s;
    cin>>s>>n;
    if (n<=s) cout<<1;
    else if (n%s==0) cout<<n/s;
    else cout<<n/s+1;

    return 0;
}