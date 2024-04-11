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
    n-=3;
    long long st=0,fi=2e9;
    while(st<=fi){
      long long te=(st+fi)/2;

      long long sig=1;
      sig+=(1+te);
      sig+=(1+2*te);
      if(sig<=n){st=te+1;}else{fi=te-1;}
    }
    cout << fi << "\n";
  }
  return 0;
}