#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

typedef bitset < N > TMagic;

bitset < N > rows[N];
bitset < N > nums[N];
set < pair < int, int > > w;
set < pair < int, int > > haveAns;

pair < int, int > cut(int x, int y) { 
  int px = (rows[x] & (~rows[y]))._Find_first();
  int py = (rows[y] & (~rows[x]))._Find_first();
  return make_pair(px, py);
}

void ins(int x, int y) {
  if((rows[x] | rows[y]) == rows[y]) return;
  haveAns.emplace(x, y);
}

void del(int x, int y) {
  if((rows[x] | rows[y]) == rows[y]) return;
  haveAns.erase(haveAns.find(make_pair(x, y)));
}

void insw(int x, int c) {
  auto it = w.lower_bound(make_pair(c, x)), temp = it; 
  if(it != w.begin() && it != w.end()) {
    temp = --it; ++it;
    del(temp -> second, it -> second);
  }
  w.emplace(c, x);
  it = w.lower_bound(make_pair(c, x));

  if(it != w.begin()) {
    temp = --it; ++it;
    ins(temp -> second, it -> second);
  }

  ++it;
  if(it != w.end()) {
    temp = --it; ++it;
    ins(temp -> second, it -> second);
  }
}

void delw(int x, int c) {
  auto it = w.find(make_pair(c, x)), temp = it;
  if(it != w.begin()) {
    temp = --it; ++it;
    del(temp -> second, it -> second);
  }
  ++it;
  if(it != w.end()){
    temp = --it; ++it;
    del(temp -> second, it -> second);
  }
  w.erase(make_pair(c, x));

  it = w.lower_bound(make_pair(c, x));
  if(it != w.begin() && it != w.end()) {
    temp = --it; ++it;
    ins(temp -> second, it -> second);
  }
}

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, m, q;
  cin >> n >> m >> q;

  for(int len = 1; len <= m; ++len) {
    for(int i = 0; i < len; ++i) nums[len][i] = 1;
  }

  for(int i = 1; i <= n; ++i) {
    insw(i, 0);
  }


  for(int i = 1; i <= q; ++i) {
    int r, a, b;
    cin >> r >> a >> b;

    delw(r, rows[r].count());
    rows[r] ^= (nums[b - a + 1] << a);
    
    insw(r, rows[r].count());

    if(!haveAns.size()) {
      cout << -1 << "\n";
    }
    else {
      auto p = *haveAns.begin();
      auto q = cut(p.first, p.second);
      if(p.first > p.second) swap(p.first, p.second);
      if(q.first > q.second) swap(q.first, q.second);
      cout << p.first << " " << q.first << " " << p.second << " " << q.second << "\n";
    }
  }


  return 0;
}