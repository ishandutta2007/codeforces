#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,k;
  cin >> n >> m >> k;
  if(n>m){swap(n,m);}
  if(n==1){
    if(m==1){cout << "1\n";return 0;}
    else{
      if(k==1){cout << "1\n";return 0;}
      else if(m%2==1){cout << "1\n";return 0;}
      else{cout << "0\n";return 0;}
    }
  }
  if(k==-1 && (n%2)!=(m%2)){cout << "0\n";return 0;}
  n--;m--;
  n%=(mod-1);m%=(mod-1);
  n*=m;n%=(mod-1);
  cout << power(2,n) << '\n';
  return 0;
}