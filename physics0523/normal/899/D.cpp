#include<bits/stdc++.h>

using namespace std;

long long f(long long tg,long long n){
  long long st=(tg+1)/2,fi=min(tg-1,n);
  return max(0ll,fi-st+1ll);
}

int main(){
  long long n;
  cin >> n;
  if(n==2){cout << "1\n";return 0;}
  if(n==3){cout << "3\n";return 0;}
  if(n==4){cout << "6\n";return 0;}
  long long k,v;
  for(long long t=10;;t*=10){
    long long tg=t-1;
    if(n+(n-1)<tg){break;}
    v=t;
  }
  long long res=0;
  for(long long i=1;i<=9;i++){
    res+=f(v*i-1,n);
  }
  cout << res << '\n';
  return 0;
}