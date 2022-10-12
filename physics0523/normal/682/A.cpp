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
  long long n,m;
  cin >> n >> m;
  long long res=0;
  vector<long long> nv=decomp(n);
  vector<long long> mv=decomp(m);
  for(int i=1;i<5;i++){
    res+=nv[i]*mv[5-i];
  }
  res+=nv[0]*mv[0];
  cout << res << '\n';
  return 0;
}