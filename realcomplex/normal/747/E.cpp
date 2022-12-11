#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 9;
vector<string>tex;
vector<int>lev;
vector<string>ans[N];
int j = 0;
int oc = 0;

void fin(int l){
  oc = max(oc,l+1);
  j++;
  if(j==lev.size())return;
  ans[l].push_back(tex[j]);
  int k;
  k = lev[j];
  for(int x = 0;x<k;x++){
    fin(l+1);
  }
}

int main(){
  string a;
  cin >> a;
  a += ',';
  string cur;
  int v = 0;
  int s = 0;
  for(auto x : a){
    if(x==','){
      if(s==0){
        tex.push_back(cur);
        v=0;
      }
      else{
        lev.push_back(v);
        cur.clear();
      } 
      s=(!s);
    }
    else{
      if(s)v=(v*10)+(x-48);
      else cur+=x;
    }
  }
  j=-1;
  //return 0;
  while(j<(int)lev.size())
    fin(0);
  cout << oc << "\n";
  for(int i = 0;i<oc;i++){
    for(auto x : ans[i])
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}