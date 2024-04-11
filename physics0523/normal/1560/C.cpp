#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long v;
    cin >> v;
    long long st=1,fi=100000,te;
    while(st<=fi){
      te=(st+fi)/2;
      if(te*te>=v){fi=te-1;}else{st=te+1;}
    }
    long long id=v-(fi*fi);
    long long el=st;
    if(id<=el){
      cout << id << ' ' << el << '\n';
    }
    else{
      cout << el << ' ' << 2*el-id << '\n';
    }
  }
  return 0;
}