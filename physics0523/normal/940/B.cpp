#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k,a,b;
  cin >> n >> k >> a >> b;

  long long res=0;
  while(n>=k){
    long long rem=n%k;
    res+=rem*a;
    n=(n/k)*k;
    long long divdl=n-(n/k);
    if(a*divdl<=b){
      res+=(n-1)*a;
      n=1;
      break;
    }
    else{
      n/=k;
      res+=b;
    }
  }
  res+=(n-1)*a;

  cout << res << '\n';
  return 0;
}