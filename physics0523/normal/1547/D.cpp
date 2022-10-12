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
    vector<int> a(n),b;
    for(auto &nx : a){cin >> nx;}
    b=a;
    for(int i=1;i<n;i++){b[i]|=b[i-1];}
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << (a[i]^b[i]);
    }cout << '\n';
  }
  return 0;
}