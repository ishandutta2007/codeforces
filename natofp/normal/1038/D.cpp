#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    if(n==1) {int x; cin>>x; cout<<x; return 0;}
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long w=0;
    w+=a[n-1];
    w-=a[0];
    for(int i=1;i<n-1;i++) w+=abs(a[i]);
    cout<<w;











    return 0;
}