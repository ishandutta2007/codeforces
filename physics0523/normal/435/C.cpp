#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<int> h(n+1,0);
  for(int i=0;i<n;i++){
    if(i%2==0){h[i+1]=h[i]-a[i];}
    else{h[i+1]=h[i]+a[i];}
  }
  int pm=-1e9;
  for(int i=0;i<=n;i++){
    pm=max(pm,-h[i]);
  }
  for(int i=0;i<=n;i++){
    h[i]+=pm;
  }
  int mx=0;
  for(int i=0;i<=n;i+=2){
    mx=max(mx,h[i]);
  }
  vector<string> res(mx);
  for(int i=0;i<n;i++){
    if(i%2==0){
      for(int j=h[i]-1;j>=h[i+1];j--){
        for(int k=0;k<mx;k++){
          if(j==k){res[k].push_back('/');}
          else{res[k].push_back(' ');}
        }
      }
    }
    else{
      for(int j=h[i];j<h[i+1];j++){
        for(int k=0;k<mx;k++){
          if(j==k){res[k].push_back('\\');}
          else{res[k].push_back(' ');}
        }
      }
    }
  }
  for(auto &nx : res){cout << nx << "\n";}
  return 0;
}