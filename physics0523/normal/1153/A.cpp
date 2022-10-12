#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,t;
  cin >> n >> t;
  pi res={1e9,1e9};
  for(int i=1;i<=n;i++){
    int s,d;
    cin >> s >> d;
    if(s<t){
      res=min(res,{s+ceil(t-s,d)*d,i});
    }
    else{
      res=min(res,{s,i});
    }
  }
  cout << res.second << '\n';
  return 0;
}