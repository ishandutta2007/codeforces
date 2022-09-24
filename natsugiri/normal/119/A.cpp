#include<iostream>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
  int n,a,b;
  cin>>a>>b>>n;
  for(;;){
    n-=gcd(a,n);
    if(n<0){
      cout<<1<<endl;
      break;
    }
    n-=gcd(b,n);
    if(n<0){
      cout<<0<<endl;
      break;
    }
  }
  return 0;
}