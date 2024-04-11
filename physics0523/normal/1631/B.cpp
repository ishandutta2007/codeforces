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
    int res=0;
    while(1){
      bool fl=true;
      for(int i=1;i<n;i++){
        if(a[i-1]!=a[i]){fl=false;break;}
      }
      if(fl){break;}
      res++;
      int lef;
      for(int i=n-1;i>=0;i--){
        if(a[n-1]!=a[i]){lef=i+1;break;}
      }
      int p=lef-1;
      for(int i=n-1;i>=lef;i--){
        a[p]=a[i];
        p--;
        if(p<0){break;}
      }
    }
    cout << res << '\n';
  }
  return 0;
}