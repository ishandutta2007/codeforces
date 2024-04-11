#include<bits/stdc++.h>
#define lim 100000000

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int k;
  queue<int> f,s;
  
  cin >> k;
  for(int i=0;i<k;i++){
    int v;
    cin >> v;
    f.push(v);
  }
  cin >> k;
  for(int i=0;i<k;i++){
    int v;
    cin >> v;
    s.push(v);
  }
  
  for(int i=1;i<=lim;i++){
    int fc=f.front();f.pop();
    int sc=s.front();s.pop();
    if(fc>sc){f.push(sc);f.push(fc);}
    else{s.push(fc);s.push(sc);}
    if(f.size()==0){cout << i << ' ' << 2 << '\n';return 0;}
    if(s.size()==0){cout << i << ' ' << 1 << '\n';return 0;}
  }
  cout << "-1\n";
  return 0;
}