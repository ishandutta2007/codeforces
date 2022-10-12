#include<bits/stdc++.h>

using namespace std;

long long f(long long x){
  for(long long i=2;;i++){
    if(x%i==0){return i;}
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    if(n%2){k--;n+=f(n);}
    cout << n+2*k << '\n';
  }
  return 0;
}