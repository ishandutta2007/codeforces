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

vector<int> w;
vector<int> el_merge(vector<int> em1,vector<int> em2){
  vector<int> res;
  reverse(em1.begin(),em1.end());
  reverse(em2.begin(),em2.end());
  while(em1.size()>0 || em2.size()>0){
    if(em1.empty()){
      while(em2.size()>0){
        res.push_back(em2.back());
        em2.pop_back();
      }
    }
    else if(em2.empty()){
      while(em1.size()>0){
        res.push_back(em1.back());
        em1.pop_back();
      }
    }
    else if(w[em1.back()]>w[em2.back()]){
      res.push_back(em1.back());
      em1.pop_back();
    }
    else{
      res.push_back(em2.back());
      em2.pop_back();
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,q;
  cin >> n >> m >> q;
  vector<int> u(m),v(m);
  w.resize(m);
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;v[i]--;
  }

  UnionFind uf(2*n);
  vector<vector<vector<int>>> el(20);
  for(int i=0;i<20;i++){el[i].resize((m>>i)+1);}

  for(int i=0;i<m;i++){el[0][i].push_back(i);}
  for(int tg=1;tg<20;tg++){
    int ful=(1<<tg);
    int han=(1<<(tg-1));
    for(int i=0;i<m;i+=ful){
      int l1=i,l2=i+han;
      if(l2>=m){
        el[tg][l1>>tg]=el[tg-1][l1>>(tg-1)];
      }
      else{
        vector<int> emg=el_merge(el[tg-1][l1>>(tg-1)],el[tg-1][l2>>(tg-1)]);
        for(auto &nx : emg){
          int id=nx;
          uf.data[2*u[id]]=-1;
          uf.data[2*u[id]+1]=-1;
          uf.data[2*v[id]]=-1;
          uf.data[2*v[id]+1]=-1;
        }
        for(auto &nx : emg){
          int id=nx;
          if(uf.findSet(2*u[id],2*v[id]+1)){continue;}
          el[tg][l1>>tg].push_back(nx);
          //cout << id << ' ';
          uf.unionSet(2*u[id],2*v[id]+1);
          uf.unionSet(2*u[id]+1,2*v[id]);
          if(uf.findSet(2*u[id],2*u[id]+1)){break;}
        }//cout << '\n';
      }
    }
  }
  while(q>0){
    q--;
    int l,r;
    cin >> l >> r;
    l--;
    vector<int> cel;
    while(l<r){
      for(int tg=19;tg>=0;tg--){
        if(l&((1<<tg)-1)){continue;}
        if(l+(1<<tg)<=r){
          cel=el_merge(cel,el[tg][l>>tg]);
          l+=(1<<tg);
          break;
        }
      }
    }
    for(auto &nx : cel){
      int id=nx;
      uf.data[2*u[id]]=-1;
      uf.data[2*u[id]+1]=-1;
      uf.data[2*v[id]]=-1;
      uf.data[2*v[id]+1]=-1;
    }
    int res=-1;
    for(auto &nx : cel){
      int id=nx;
      //cout << q << ' ' << id << '\n';
      if(uf.findSet(2*u[id],2*v[id]+1)){continue;}
      uf.unionSet(2*u[id],2*v[id]+1);
      uf.unionSet(2*u[id]+1,2*v[id]);
      if(uf.findSet(2*u[id],2*u[id]+1)){res=w[nx];break;}
    }
    cout << res << '\n';
  }
  return 0;
}