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
    vector<int> im(n+2);
    for(int i=1;i<=n;i++){
      int l;
      cin >> l;
      im[max(1,i+1-l)]++;
      im[i+1]--;
    }
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      if(im[i]){cout << "1";}else{cout << "0";}
      im[i+1]+=im[i];
    }cout << '\n';
  }
  return 0;
}