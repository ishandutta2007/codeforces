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
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      sig+=v;
    }
    if(sig%n==0){cout << "0\n";}
    else{cout << "1\n";}
  }
  return 0;
}