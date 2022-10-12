#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n,vector<int>(m));
  for(auto &nx : a){
    for(auto &ny : nx){cin >> ny;}
  }
  vector<int> r(n),c(m);
  for(int i=0;i<n;i++){r[i]=i;}
  for(int i=0;i<m;i++){c[i]=i;}
  while(q>0){
    q--;
    string s;
    int x,y;
    cin >> s >> x >> y;
    x--;y--;
    if(s[0]=='r'){swap(r[x],r[y]);}
    if(s[0]=='c'){swap(c[x],c[y]);}
    if(s[0]=='g'){cout << a[r[x]][c[y]] << '\n';}
  }
  return 0;
}