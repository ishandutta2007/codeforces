#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int * a=new long long int[4];
    for(int i=0;i<4;i++) cin>>a[i];
    sort(a,a+4);
    long long int x=a[3]-a[0];
    long long int y=a[1]-x;
    long long int z=a[3]-x-y;
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}