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

bool jud(pi a,pi b){
  if(a.second<b.first){return false;}
  if(b.second<a.first){return false;}
  return true;
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
    UnionFind uf(n+1);
    vector<pi> seg(n+1);
    vector<int> col(n+1);
    vector<pi> ev;
    for(int i=1;i<=n;i++){
      cin >> col[i];
      cin >> seg[i].first >> seg[i].second;
      ev.push_back({seg[i].first,-i});
      ev.push_back({seg[i].second,i});
    }
    sort(ev.begin(),ev.end());
    vector<priority_queue<pi,vector<pi>,greater<pi>>> pq(2);
    for(auto &nx : ev){
      int cur=nx.second;
      if(cur<0){ //sta
        cur*=-1;
        int opp=1-col[cur];
        pi od={-1,-1};
        while(!pq[opp].empty()){
          od=pq[opp].top();pq[opp].pop();
          uf.unionSet(cur,od.second);
        }
        if(od.first!=-1){pq[opp].push(od);}
        pq[col[cur]].push({seg[cur].second,cur});
      }
      else{ //fin
        if(pq[col[cur]].top().second==cur){
          pq[col[cur]].pop();
        }
      }
    }
    int res=0;
    for(int i=1;i<=n;i++){
      if(uf.root(i)==i){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}