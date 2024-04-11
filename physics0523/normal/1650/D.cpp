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
    for(auto &nx : a){
      cin >> nx;
      nx--;
    }
    vector<int> res;
    for(int i=n-1;i>=0;i--){
      vector<int> na(i);
      int tg=0;
      for(int j=0;j<=i;j++){
        if(a[j]==i){tg=j;}
      }
      tg++;
      res.push_back(tg%(i+1));
      for(int j=0;j<=i;j++){
        int np=((i+1)+j-tg)%(i+1);
        if(np!=i){na[np]=a[j];}
      }
      a.swap(na);
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}