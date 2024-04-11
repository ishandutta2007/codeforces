#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

string s;
int res;

pair<int,int> rep(int v,Graph &g){
  pair<int,int> cur={0,0};
  if(s[v]=='B'){cur.first++;}
  else{cur.second++;}
  for(auto &nx : g[v]){
    pair<int,int> st=rep(nx,g);
    cur.first+=st.first;
    cur.second+=st.second;
  }
  if(cur.first==cur.second){res++;}
  return cur;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    Graph g(n);
    for(int i=1;i<n;i++){
      int p;
      cin >> p;
      p--;
      g[p].push_back(i);
    }
    cin >> s;
    res=0;
    rep(0,g);
    cout << res << '\n';
  }
  return 0;
}