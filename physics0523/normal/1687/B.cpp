#include<bits/stdc++.h>

using namespace std;

long long ask(string &s){
  cout << "? " << s << '\n';
  fflush(stdout);
  long long v;
  cin >> v;
  return v;
}

void ans(long long x){
  cout << "! " << x << '\n';
  fflush(stdout);
}

using pl=pair<long long,long long>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pl> pv;
  for(int i=0;i<m;i++){
    string q;
    for(int j=0;j<m;j++){
      if(i==j){q.push_back('1');}
      else{q.push_back('0');}
    }
    pv.push_back({ask(q),i});
  }
  sort(pv.begin(),pv.end());

  long long res=0;
  string q;
  for(int i=0;i<m;i++){q.push_back('0');}
  for(auto &nx : pv){
    // cout << nx.first << ':' << nx.second << '\n';
    long long est=res+nx.first;
    q[nx.second]='1';
    if(ask(q)==est){res=est;}
    else{q[nx.second]='0';}
  }

  ans(res);
  return 0;
}