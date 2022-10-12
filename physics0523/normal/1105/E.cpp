#include<bits/stdc++.h>

using namespace std;
using pis=pair<int,string>;

// https://judge.yosupo.jp/submission/64861
#define rep(i,x) for(int i=0;i<x;i++)

//0-indexed
template<int V>
struct MaximumClique {
	using B = bitset<V>;
	vector<B>g, col_buf;
	MaximumClique(int N) : g(N), col_buf(N) {}
	struct pp{
		int idx, col, deg;
		pp(int idx, int col, int deg) : idx(idx), col(col), deg(deg) {}
	};
	void add_edge(int a, int b) {
		g[a].set(b);
		g[b].set(a);
	}
	vector<int>now,clique;
	//g -> 
	//col_buf -> 
	//rem (, -1, )
	void dfs(vector<pp>&rem){
		if(clique.size() < now.size()) clique = now;
		//
		sort(begin(rem), end(rem), [](const pp &a, const pp &b) {
			return a.deg > b.deg;
		});
		//
		//()
		int max_c = 1;
		for(auto &p : rem) {
			p.col = 0;
			while((g[p.idx] & col_buf[p.col]).any()) ++p.col;
			max_c = max(max_c, p.idx + 1);
			col_buf[p.col].set(p.idx);
		}
		rep(i,max_c) col_buf[i].reset();
		//
		sort(begin(rem), end(rem), [&](const pp &a, const pp &b) {
			return a.col < b.col;
		});
		//rem
		for(; !rem.empty(); rem.pop_back()) {
			//
			auto &p = rem.back();
			//clique
			if(now.size() + p.col + 1 <= clique.size()) break;
			vector<pp>nrem;
			B bs;
			for(auto &q : rem) {
				//
				if(g[p.idx][q.idx]) {
					nrem.emplace_back(q.idx, -1, 0);
					bs.set(q.idx);
				}
			}
			//
			for(auto &q : nrem) {
				q.deg = (bs & g[q.idx]).count();
			}
			now.emplace_back(p.idx);
			dfs(nrem);
			now.pop_back();
		}
	}
	vector<int> solve() {
		vector<pp> remark;
		for(int i = 0; i < g.size(); i++) {
			remark.emplace_back(i, -1, (int) g[i].count());
		}
		shuffle(remark.begin(), remark.end(), mt19937(61471));
		dfs(remark);
		return clique;
	}
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<pis> act(n);
  set<string> sts;
  for(int i=0;i<n;i++){
    cin >> act[i].first;
    if(act[i].first==2){
      cin >> act[i].second;
      sts.insert(act[i].second);
    }
  }
  map<string,int> id;
  int cid=0;
  for(auto &nx : sts){
    id[nx]=cid;
    cid++;
  }

  MaximumClique<42> kaede(cid);
  bool eg[42][42];
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      eg[i][j]=true;
    }
  }

  set<int> st;
  for(int i=n-1;i>=0;i--){
    if(act[i].first==1){
      for(auto &nx : st){
        for(auto &ny : st){
          eg[nx][ny]=false;
        }
      }
      st.clear();
    }
    else{st.insert(id[act[i].second]);}
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<i;j++){
      if(eg[i][j]){kaede.add_edge(i,j);}
    }
  }
  auto ret = kaede.solve();
  cout << ((int)ret.size()) << '\n';
  return 0;
}