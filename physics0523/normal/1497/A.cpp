#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(a[j]==i){swap(a[i],a[j]);}
      }
    }
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << a[i];
    }
    cout << "\n";
  }
  return 0;
}