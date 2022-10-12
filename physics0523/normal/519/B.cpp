#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  multiset<int> ms;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    ms.insert(v);
  }
  for(int t=1;t<=2;t++){
    multiset<int> ns;
    for(int i=0;i<n-t;i++){
      int v;
      cin >> v;
      //cout << '[' << v << "]\n";
      ms.erase(ms.find(v));
      ns.insert(v);
    }
    cout << (*ms.begin()) << '\n';
    ms.swap(ns);
  }
  return 0;
}