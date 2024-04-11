#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x,k;
  cin >> x >> k;
  vector<long long> mem;
  for(int i=0;i<k;i++){
    long long typ;
    cin >> typ;
    if(typ==1){
      long long p,q;
      cin >> p >> q;
      mem.push_back(p);
      mem.push_back(q);
    }
    else{
      long long p;
      cin >> p;
      mem.push_back(p);
    }
  }
  mem.push_back(0);
  mem.push_back(x);
  sort(mem.begin(),mem.end());
  long long mi=0,ma=0;
  for(long long i=1;i<mem.size();i++){
    long long d=mem[i]-mem[i-1]-1;
    mi+=llceil(d,2);
    ma+=d;
  }
  cout << mi << ' ' << ma << '\n';
  return 0;
}