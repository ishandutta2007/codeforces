#include <iostream>
using namespace std;
int main(){
  long n,k,a[1000000],i,l=0,m,j;
  cin>>n>>k;
  for (i=0;i<n;i++){
    cin>>a[i];
      if(i<k){
       l+= a[i];
      }
  }
  m = l;
  for (i=k;i<n;i++){
    l += a[i]-a[i-k];
    if(l<m){
      m=l;
      j = i-k+1;
    }
  }
  cout<<j+1<<endl;
  return 0;
}