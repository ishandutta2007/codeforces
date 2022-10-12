#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    for(int i=0;i<k;i++){
      int tg=-1;
      for(int j=0;j<n-1;j++){
        if(a[j]>0){tg=j;break;}
      }
      if(tg==-1){break;}
      a[tg]--;
      a[n-1]++;
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}