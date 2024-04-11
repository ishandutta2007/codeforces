#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ile=a[0];
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==ile) res++;
    }
    if(res>n/2) {cout<<"Bob"; return 0;}
    else {cout<<"Alice"; return 0;}

    return 0;
}