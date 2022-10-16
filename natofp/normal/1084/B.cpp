#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,s;
    cin>>n>>s;
    long long int * a=new long long int [n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    if(sum<s) {cout<<-1; return 0;}
    long long int ile=0;
    for(int i=1;i<n;i++) ile+=(a[i]-a[0]);
    s-=ile;
    if(s<=0) {cout<<a[0]; return 0;}
    cout<<a[0]-(s/n+bool(s%n));
    return 0;
}