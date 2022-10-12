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
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> eg(m);
	UnionFind uf(n);
	vector<int> b(n),vc(n);
	for(int i=0;i<m;i++){
		cin >> eg[i].first >> eg[i].second;
		eg[i].first--;
		eg[i].second--;
		vc[eg[i].first]++;
		vc[eg[i].second]++;
		uf.unionSet(eg[i].first,eg[i].second);
	}
	for(int i=0;i<m;i++){b[uf.root(eg[i].first)]++;}
	for(int i=0;i<n;i++){
		if(vc[i]!=2){b[uf.root(i)]=-1;}
	}
	int res=0;
	for(int i=0;i<n;i++){
		if(uf.root(i)==i){
			if(uf.size(i)==b[i]){res++;}
		}
	}
	cout << res << '\n';
  return 0;
}