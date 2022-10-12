#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  long long st=1,fi=2e9;
  while(st<=fi){
    long long te=(st+fi)/2;
    long long f=((1+te)*te)/2;
    f-=(n-te);
    if(f<k){st=te+1;}else{fi=te-1;}
  }
  cout << n-st << "\n";
  return 0;
}