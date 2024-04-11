#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
LL k,n,i,m;
LL a[100000];
int main(){
  cin>>n>>k;
  k--;
  for(i=0;i<n;i++){cin>>a[i];}
  sort(a,a+n);
  for(i=0;i<n;){
    m=0;
    for(;i+m<n&&a[i]==a[i+m];m++);
    if(k<m*n){
      cout<<a[i]<<' '<<a[k/m]<<endl;
      return 0;
    }
    i+=m;
    k-=m*n;
  }
  return 0;
}