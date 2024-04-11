#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  string res;
  if(k>=3){
    char las=('a'+k-1);
    for(char i='a';i<=las;i++){
      res.push_back(i);
      res.push_back(i);
      for(char j=i+2;j<=las;j++){
        if(i=='a' && j==las){continue;}
        res.push_back(j);
        res.push_back(i);
      }
    }
    res.push_back('a');
    for(char i=las;i>='b';i--){res.push_back(i);}
  }
  else if(k==2){res="aabb";}
  else if(k==1){res="a";}
  while(res.size()<n){res+=res;}
  for(int i=0;i<n;i++){cout << res[i];}
  cout << '\n';
  return 0;
}