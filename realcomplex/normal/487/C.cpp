#include <bits/stdc++.h>

using namespace std;

int n;

int pow(int a,int b){
  if(b==0)return 1;
  int half=pow(a,b/2);
  if(b%2)
    return (1LL*((1LL*half*half)%n)*a)%n;
  else
    return (1LL*half*half)%n;
}

int main(){
  cin >> n;
  if(n==1){
    cout << "YES\n1";
    return 0;
  }
  if(n==2){
    cout << "YES\n1\n2\n";
    return 0;
  }
  if(n==4){
    cout << "YES\n1\n3\n2\n4\n";
    return 0;
  }
  for(int i = 2;i*i<=n;i++){
    if(n%i==0){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for(int i = 0;i<n;i++){
    cout << 1+pow(i,n-2) << "\n";
  }
  return 0;
}