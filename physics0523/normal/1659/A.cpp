#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,r,b;
    cin >> n >> r >> b;
    vector<int> a(b+1,0);
    for(int i=0;i<r;i++){
      a[i%(b+1)]++;
    }
    for(int i=0;i<b+1;i++){
      for(int j=0;j<a[i];j++){cout << "R";}
      if(i==b){break;}
      cout << "B";
    }cout << '\n';
  }
  return 0;
}