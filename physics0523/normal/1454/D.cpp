#include<bits/stdc++.h>

using namespace std;

int main(){
  long long t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<pair<long long,long long>> vp;
    long long mx=0;
    for(long long i=2;i*i<=n;i++){
      if((n%i)!=0){continue;}
      long long cr=0;
      while((n%i)==0){n/=i;cr++;}
      vp.push_back(make_pair(i,cr));
      mx=max(mx,cr);
    }
    if(n!=1){
      long long j=n;
      long long cr=0;
      while((n%j)==0){n/=j;cr++;}
      vp.push_back(make_pair(j,cr));
      mx=max(mx,cr);
    }
    cout << mx << '\n';
    vector<long long> res(mx,1);
    for(auto &e : vp){
      for(int i=0;i<e.second;i++){res[mx-1-i]*=e.first;}
    }
    for(int i=0;i<mx;i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}