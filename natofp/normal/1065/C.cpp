#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int * a;
    a=new int[n];
    vector<int> ile(200005,0);
    for(int i=0;i<n;i++) {cin>>a[i]; ile[a[i]]++;}
    sort(a,a+n);
    int ans=0;
    int akt=0;
    int sum=0;
    for(int i=a[n-1];i>=a[0];i--)
    {
        if(sum+akt>k) {ans++; sum=0;}
        sum+=akt;
        akt+=ile[i];
    }
    if(sum>0) ans++;
    cout<<ans;
    return 0;
}