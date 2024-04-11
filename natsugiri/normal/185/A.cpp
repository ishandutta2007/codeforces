#include<iostream>

using namespace std;


typedef long long LL;
const LL MOD =1000000007;
LL pow(LL x, LL y){
  if(y<1)return 1;
  if(y%2)return x*pow(x, y-1)%MOD;
  return pow(x*x%MOD, y/2);
}

int main(){
  LL n; 
  cin>>n;
  LL a=pow(4, n), b=pow(2, n);
  LL c=(a-b)%MOD*pow(2, MOD-2)%MOD;
  cout<<(c+b+MOD)%MOD<<endl;
  return 0;
}