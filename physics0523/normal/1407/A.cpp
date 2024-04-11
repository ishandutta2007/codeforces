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
    int sig=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      sig+=a[i];
    }
    int cnt,ele;
    int bd=(n/2);
    if(bd%2){bd++;}
    
    if(sig>=bd){cnt=bd;ele=1;}
    else{cnt=(n-sig);ele=0;}
    cout << cnt << '\n';
    for(int i=0;i<cnt;i++){
      if(i){cout << ' ';}
      cout << ele;
    }cout << '\n';
  }
  return 0;
}