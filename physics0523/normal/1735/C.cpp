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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    cin >> l;
    string s;
    cin >> s;

    UnionFind uf(26);
    int rem=26;
    vector<char> mem(26,'-');
    vector<int> used(26,0);
    string res;

    for(auto &nx : s){
      if(mem[nx-'a']=='-'){
        for(char i='a';i<='z';i++){
          if(nx==i){continue;}
          if(used[i-'a']){continue;}

          if(uf.root(nx-'a')!=uf.root(i-'a')){
            uf.unionSet(nx-'a',i-'a');
            mem[nx-'a']=i;
            used[i-'a']=1;
            rem--;
            break;
          }
          else if(rem==1){
            mem[nx-'a']=i;
            used[i-'a']=1;
            rem--;
            break;
          }
        }
      }
      res.push_back(mem[nx-'a']);
    }
    cout << res << "\n";
  }
  return 0;
}