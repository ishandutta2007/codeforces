#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> tag(n);
  for(int i=0;i<n;i++){cin >> tag[i];}
  for(int i=n-2;i>=0;i--){
    int l=tag[i].size();
    for(int j=0;j<l;j++){
      if(tag[i][j]>tag[i+1][j]){
        tag[i].erase(j,l-j);
        break;
      }
      else if(tag[i][j]<tag[i+1][j]){break;}
    }
  }
  for(int i=0;i<n;i++){cout << tag[i] << '\n';}
  return 0;
}