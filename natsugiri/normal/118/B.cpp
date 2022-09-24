#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,i,j;
  cin>>n;
  for(i=0;i<=n;i++){
    cout<<string((n-i)*2,' ');
    cout<<0;
    for(j=0;j<i;j++){
      cout<<' '<<j+1;
    }
    for(j=0;j<i;j++){
      cout<<' '<<i-j-1;
    }
    cout<<endl;
  }
  for(i=0;i<n;i++){
    cout<<string((i+1)*2,' ');
    cout<<0;
    for(j=0;j<n-i-1;j++){
      cout<<' '<<j+1;
    }
    for(j=0;j<n-i-1;j++){
      cout<<' '<<n-i-j-2;
    }
    cout<<endl;
  }
  return 0;
}