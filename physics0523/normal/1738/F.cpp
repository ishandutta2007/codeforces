#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

using pi=pair<int,int>;

int ask(int u){
  cout << "? " << u << "\n";
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

void ans(vector<int> &c){
  cout << "!";
  for(auto &nx : c){
    cout << " " << nx;
  }
  cout << "\n";
  fflush(stdout);
  return;
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> deg(n+1);
    priority_queue<pi> pq;
    for(int i=1;i<=n;i++){
      cin >> deg[i];
      pq.push({deg[i],i});
    }

    UnionFind uf(n+1);
    set<int> st;
    while(!pq.empty()){
      pi od=pq.top();pq.pop();
      if(st.find(od.second)!=st.end()){continue;}
      st.insert(od.second);
      for(int i=0;i<deg[od.second];i++){
        int ca=ask(od.second);
        uf.unionSet(od.second,ca);

        if(st.find(ca)!=st.end()){break;}
        st.insert(ca);
      }
    }

    vector<int> res;
    for(int i=1;i<=n;i++){
      res.push_back(uf.root(i));
    }
    ans(res);
  }
  return 0;
}