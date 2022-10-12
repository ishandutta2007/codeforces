#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int h,w;
    cin >> h >> w;
    vector<int> res;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        int d1=i+j;
        int d2=i+(w-1-j);
        int d3=(h-1-i)+j;
        int d4=(h-1-i)+(w-1-j);
        res.push_back(max({d1,d2,d3,d4}));
      }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<h*w;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}