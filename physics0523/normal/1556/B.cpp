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
    vector<long long> a(n),ks;
    long long k=0,g=0;
    for(long long i=0;i<n;i++){
      cin >> a[i];
      if(a[i]%2==0){g++;}else{k++;ks.push_back(i);}
    }
    long long res=1e18,cres,p;
    if(g==k){
      cres=0;p=0;
      for(long long i=0;i<n;i+=2){
        cres+=abs(ks[p]-i);p++;
      }
      res=min(res,cres);
      cres=0;p=0;
      for(long long i=1;i<n;i+=2){
        cres+=abs(ks[p]-i);p++;
      }
      res=min(res,cres);
      cout << res << '\n';
    }
    else if(g+1==k){
      cres=0;p=0;
      for(long long i=0;i<n;i+=2){
        cres+=abs(ks[p]-i);p++;
      }
      res=min(res,cres);
      cout << res << '\n';
    }
    else if(g==k+1){
      cres=0;p=0;
      for(long long i=1;i<n;i+=2){
        cres+=abs(ks[p]-i);p++;
      }
      res=min(res,cres);
      cout << res << '\n';
    }
    else{
      cout << "-1\n";
    }
  }
  return 0;
}