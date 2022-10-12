#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int dv(int x){
  while((x&1)==0){x/=2;}
  return x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    multiset<int> a,b;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      a.insert(dv(v));
    }
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      b.insert(dv(v));
    }

    bool jud=true;
    while(jud && (!a.empty())){
      auto it=b.end();
      it--;
      long long v=(*it);
      b.erase(it);

      auto ait=a.find(v);
      if(ait!=a.end()){
        a.erase(ait);
      }
      else{
        v/=2;
        if(v==0){jud=false;break;}
        b.insert(v);
      }
    }
    if(jud){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}