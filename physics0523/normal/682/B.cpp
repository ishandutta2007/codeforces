#include<bits/stdc++.h>

using namespace std;

vector<long long> decomp(long long x){
  vector<long long> mem(5,x/5);
  for(int i=1;i<=(x%5);i++){mem[i]++;}
  return mem;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  int res=1;
  for(auto &nx : a){
    if(res<=nx){res++;}
  }
  cout << res << '\n';
  return 0;
}