#include <bits/stdc++.h>

using namespace std;

const int N = 3030;
const int lcm = 2520;

int n; 
int val[N];
vector < int > edges[N];

int cnt[N];
int mark[N][N];
int answered[N][N];
pair < int, int > previous[N][N];

int go(int x, int mod) {
 // if(x != 2) cout << "dfs-ing: " << x << " " << mod % edges[x].size() << endl;
  if(answered[x][mod]) return answered[x][mod];

  mark[x][mod] = 1;

  int y = edges[x][mod % edges[x].size()];
  int newmod = (mod + val[y] + lcm) % lcm;

  if(mark[y][newmod]) {
    if(answered[y][newmod]) {
      return answered[x][mod] = answered[y][newmod];
    }
    list < int > vertices;
  //  cout << "Working on: " << y << " "<< newmod << " " << previous[3][1] << endl;
    for(int u = x, v = mod; ;) {
      vertices.push_back(u);

      
      if(u == y && v == newmod) break;
      int w = previous[u][v].second;
      u = previous[u][v].first;
      v = w;
    }
    int ret = 0;
    for(int x : vertices) if(!cnt[x]) {
      ++ret;
      cnt[x] = 1;
    }
    for(int x : vertices) cnt[x] = 0;
  
    answered[x][mod] = ret;
  }
  else {
    previous[y][newmod] = make_pair(x, mod);
    answered[x][mod] = go(y, newmod);
  }

  return answered[x][mod];
}

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> val[i], val[i] %= lcm;

  for(int i = 1; i <= n; ++i) {
    int sz; cin >> sz;
    while(sz--) {
      int x; cin >> x;
      edges[i].push_back(x);
    }
  }

  int q; cin >> q;
  while(q--) {
    int x, y; cin >> x >> y;
    y += val[x];
    y %= lcm; y += lcm; y %= lcm;
  //  cout << x << " " << y << endl;
  //  go(x, y);
    cout << go(x, y) << "\n";
  }

  return 0;
}