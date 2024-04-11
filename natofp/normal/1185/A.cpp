#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;

int main()
{
    long long int a[3];
    long long int d;
    cin>>a[0]>>a[1]>>a[2];
    cin>>d;
    sort(a,a+3);
    long long int x=a[1]-a[0];
    long long int y=a[2]-a[1];
    long long int res=0;
    if(x<d) res+=d-x;
    if(y<d) res+=d-y;
    cout<<res;
    return 0;
}