#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<int,int> a;
int n;
int res=1;
bool zrob()
{
    n++;
    while(n%10==0) n/=10;
    if(a[n]==true) return false;
    a[n]=true;
    res++;
    return true;
}

int main()
{
    cin>>n;
    a[n]=true;
    while(zrob());
    cout<<res;
    return 0;
}