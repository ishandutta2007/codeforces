#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int f(int x){
  return 2*ceil(x,3)-1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi> res;
  int bas=f(n);
  int h=1;
  for(int i=1;i<=bas;i+=2){
    res.push_back({h,i});
    h++;
  }
  for(int i=2;i<=bas;i+=2){
    res.push_back({h,i});
    h++;
  }
  if(n%3==0){res.push_back({bas+1,bas+1});}

  cout << res.size() << '\n';
  for(auto &nx : res){
    cout << nx.first << ' ' << nx.second << '\n';
  }
  return 0;
}