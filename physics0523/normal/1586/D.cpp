#include<bits/stdc++.h>

using namespace std;

int ask(vector<int> &a){
  cout << "?";
  for(auto &nx : a){
    cout << ' ' << nx;
  }cout << '\n';
  fflush(stdout);
  int v;
  cin >> v;
  return v;
}

int main(){
  int n;
  cin >> n;
  int bt=n;
  for(int i=1;i<n;i++){
    vector<int> av;
    for(int j=0;j<n-1;j++){av.push_back(i);}
    av.push_back(n);
    if(ask(av)!=0){bt=i;break;}
  }
  vector<int> p(n);
  p[n-1]=bt;
  for(int i=1;i<=n;i++){
    if(i==bt){continue;}
    vector<int> av;
    for(int j=0;j<n-1;j++){av.push_back(bt);}
    av.push_back(i);
    p[ask(av)-1]=i;
  }
  cout << "!";
  for(auto &nx : p){
    cout << ' ' << nx;
  }cout << '\n';
  fflush(stdout);
  return 0;
}