#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,res=1,cur=0;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    if(cur+v > m){
      res++;
      cur=v;
    }
    else{
      cur+=v;
    }
  }
  cout << res << "\n";
  return 0;
}