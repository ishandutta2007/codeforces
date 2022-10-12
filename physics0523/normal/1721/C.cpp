#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}

    multiset<int> bst,errm1;
    for(int i=0;i<n;i++){
      bst.insert(b[i]);
    }
    for(int i=1;i<n;i++){
      if(a[i]<=b[i-1]){continue;}
      errm1.insert(i);
    }
    errm1.insert(n);

    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      auto it=bst.lower_bound(a[i]);
      cout << (*it)-a[i];
    }cout << "\n";

    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      auto it=errm1.lower_bound(i+1);
      int tg=(*it)-1;
      cout << b[tg]-a[i];
    }cout << "\n";
  }
  return 0;
}