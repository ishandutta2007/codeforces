#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int res=-1;
    for(int i=0;i<n;i++)
    {
        if(res+1<a[i]) {cout<<i+1; return 0;}
        if(a[i]>res) res++;
    }
    cout<<-1;
    return 0;
}