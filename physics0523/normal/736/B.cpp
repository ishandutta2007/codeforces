#include<bits/stdc++.h>

using namespace std;

bool isprime(int x){
  if(x<=1){return false;}
  for(int i=2;i*i<=x;i++){
    if(x%i==0){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if(n%2==0){
    if(n==2){cout << "1\n";}
    else{cout << "2\n";}
  }
  else{
    if(isprime(n)){cout << "1\n";}
    else if(isprime(n-2) && isprime(2)){cout << "2\n";}
    else{cout << "3\n";}
  }
  return 0;
}