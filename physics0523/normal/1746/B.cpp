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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int p=0,q=n-1,res=0;
    while(p<q){
      while(p<q && a[p]==0){p++;}
      if(p>=q){break;}
      while(p<q && a[q]==1){q--;}
      if(p>=q){break;}
      swap(a[p],a[q]);
      res++;
    }
    cout << res << "\n";
  }
  return 0;
}