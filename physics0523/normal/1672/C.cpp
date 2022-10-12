#include<bits/stdc++.h>

using namespace std;

int feq(vector<int> &a){
  int n=a.size(),res=0;
  for(int i=1;i<n;i++){
    if(a[i-1]==a[i]){res++;}
  }
  return res;
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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    if(feq(a)<=1){cout << "0\n";continue;}
    int mi=1e9,ma=-1e9;
    for(int i=1;i<n;i++){
      if(a[i-1]==a[i]){
        mi=min(mi,i);
        ma=max(ma,i);
      }
    }
    cout << max(1,ma-mi-1) << '\n';
  }
  return 0;
}