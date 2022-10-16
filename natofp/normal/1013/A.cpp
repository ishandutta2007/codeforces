#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int * a;
    int * b;
    a=new int[n];
    b=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int sum1,sum2;
    sum1=0; sum2=0;
    for(int i=0;i<n;i++) sum1+=a[i];
    for(int i=0;i<n;i++) sum2+=b[i];
    if(sum1>=sum2) cout<<"Yes";
    else cout<<"No";
    return 0;
}