#include <bits/stdc++.h>
using namespace std;
long long n,k,l,a[100010],t;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int sol=a[n-1]-a[0],r=n-1;
    while(l<r&&k){
        if(l<n-r)l++,t=min(a[l]-a[l-1],k/l),k-=t*l;
        else t=min(a[r]-a[r-1],k/(n-r)),k-=t*(n-r),r--;
        sol-=t;
    }
    cout<<sol;
}