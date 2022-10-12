#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k,res=0;
    cin >> n >> k;
    vector<long long> a(n);
    multiset<long long> ms;
    for(auto &nx : a){
      cin >> nx;
      res+=nx/k;
      nx%=k;
      ms.insert(nx);
    }
    while(ms.size()>=2){
      auto it=ms.begin();
      long long v1=(*it);
      ms.erase(it);
      
      auto tg=ms.lower_bound(k-v1);
      if(tg!=ms.end()){
        res++;ms.erase(tg);
      }
    }
    cout << res << '\n';
  }
  return 0;
}