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
    cout << n << "\n";
    vector<int> res;
    for(int i=0;i<n;i++){res.push_back(i+1);}
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j){cout << " ";}
        cout << res[j];
      }cout << "\n";
      if(i!=n-1){swap(res[i],res[i+1]);}
    }
  }
  return 0;
}