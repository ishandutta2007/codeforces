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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    reverse(a.begin(),a.end());
    long long res=0;
    for(int i=1;i<a.size();i++){
      while(a[i]>0 && a[i-1]<=a[i]){
        res++;a[i]/=2;
      }
      if(a[i-1]==a[i]){res=-1;break;}
    }
    cout << res << '\n';
  }
  return 0;
}