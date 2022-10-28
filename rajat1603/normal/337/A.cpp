#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    unsigned long k,n,a[100010],i,j,ans=999999999;
    cin>>k>>n;
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-k+1;i++){  
        ans = min(ans,a[i+k-1]-a[i]);
    }
    cout<<ans;
}