#include<bits/stdc++.h>

using namespace std;

bool jud(long long x){
  long long mx=x;
  while(mx>0){
    if(mx%10!=0){
      if(x%(mx%10)!=0){return false;}
    }
    mx/=10;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    while(!jud(n)){n++;}
    cout << n << '\n';
  }
}