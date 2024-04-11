#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long k=1;
    while(k<=1350851717672992089){
      if((n%(3*k))/k == 2){
        n/=(3*k);
        n++;
        n*=(3*k);
      }
      k*=3;
    }
    cout << n << '\n';
  }
}