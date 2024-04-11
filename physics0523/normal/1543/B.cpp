#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long sig=0;
    for(long long i=0;i<n;i++){
      long long v;
      cin >> v;
      sig+=v;
    }
    long long md=sig%n;
    cout << (md)*(n-md) << '\n';
  }
  return 0;
}