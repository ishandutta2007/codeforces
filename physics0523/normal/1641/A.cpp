#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    multiset<long long> ms;
    for(auto &nx : a){
      cin >> nx;
      ms.insert(nx);
    }
    long long res=0;
    while(!ms.empty()){
      auto it=ms.begin();
      long long tg=(*it)*x;
      if(ms.find(tg)!=ms.end()){ms.erase(ms.find(tg));}
      else{res++;}
      ms.erase(it);
    }
    cout << res << '\n';
  }
  return 0;
}