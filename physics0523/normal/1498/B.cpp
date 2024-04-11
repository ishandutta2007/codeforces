#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,w;
    cin >> n >> w;
    multiset<int> ms;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      ms.insert(v);
    }
    for(int h=1;;h++){
      int rw=w;
      while(rw>0 && !ms.empty()){
        auto it=ms.lower_bound(rw+1);
        if(it==ms.begin()){break;}
        it--;
        rw-=(*it);
        ms.erase(it);
      }
      if(ms.empty()){cout << h << '\n';break;}
    }
  }
  return 0;
}