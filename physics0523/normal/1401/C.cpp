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
    int gm=2e9;
    for(auto &nx : a){
      cin >> nx;
      gm=min(gm,nx);
    }
    vector<int> keep;
    for(auto &nx : a){
      if(nx%gm==0){
        keep.push_back(nx);
        nx=-1;
      }
    }
    sort(keep.begin(),keep.end());
    int pt=0;
    for(auto &nx : a){
      if(nx==-1){
        nx=keep[pt];
        pt++;
      }
    }
    bool jud=true;
    for(int i=1;i<n;i++){
      if(a[i-1]>a[i]){jud=false;}
    }
    if(jud){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}