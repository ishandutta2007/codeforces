#include<bits/stdc++.h>

using namespace std;

long long f(long long n,long long x){
  long long res=0;
  while(n>0){
    n/=x;
    res+=n;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long a,b;
  cin >> a >> b;
  map<long long,long long> mp;
  for(long long i=2;i*i<=b;i++){
    while(b%i==0){
      b/=i;
      mp[i]++;
    }
  }
  if(b>=2){mp[b]++;}

  long long res=8e18;
  for(auto &nx : mp){
    res=min(res,f(a,nx.first)/nx.second);
  }

  cout << res << "\n";
  return 0;
}