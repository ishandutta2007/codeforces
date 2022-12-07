#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
char arr[N];

struct SegmentTree{
  struct node{
    int a[26];
    int c;
  };
  node it[N * 8];
  node answer;
  node add(node &u, node v){
    for(int i = 0; i < 26; ++i){
      u.a[i] += v.a[i];
    }
    return u;
  }
  void init(){
    for(int i = 0; i < N * 8; ++i){
      it[i].c = -1;
    }
  }
  void solve(int i, int l, int r){
    if(it[i].c != -1){
      memset(it[i].a, 0, sizeof it[i].a);
      it[i].a[it[i].c] = r - l + 1;
      int mid = (l + r) >> 1;
      it[i * 2].c = it[i].c;
      it[i * 2 + 1].c = it[i].c;
    }
    it[i].c = -1;
  }
  void upd(int i, int l, int r, int d, int c, int val){
    solve(i, l, r);
    if(l >= d && r <= c){
      it[i].c = val;
      //cerr << i << " " << l << " " << r << " -> " << d << " " << c << endl;
      solve(i, l, r);
      return;
    }
    if(l > c || d > r){
      return;
    }
    int mid = (l + r) >> 1;
    upd(i * 2, l, mid, d, c, val);
    upd(i * 2 + 1, mid + 1, r, d, c, val);
    for(int c = 0; c < 26; ++c){
      it[i].a[c] = it[i * 2 + 1].a[c] + it[i * 2].a[c];
    }
  }
  void query(int i, int l, int r, int d, int c){
    solve(i, l, r);
    if(l > c || d > r){
      return;
    }
    if(l >= d && r <= c){
      add(answer, it[i]);
      return;
    }
    int mid = (l + r) >> 1;
    query(i * 2, l, mid, d, c);
    query(i * 2 + 1, mid + 1, r, d, c);
  }
  node ask(int l, int r){
    memset(answer.a, 0, sizeof answer.a);
    query(1, 1, n, l, r);
  }
  void update(int l, int r, int type){
    ask(l, r);
    int fr = 0, to = 25, current = l, add = 1;
    if(type == 0){
      fr = 25;
      to = 0;
      add = -1;
    }
    //cerr << fr << " " << to << endl;
    for(int i = fr; i != to + add; i += add){
      if(answer.a[i] > 0){
        int s = answer.a[i];
        upd(1, 1, n, current, current + s - 1, i);
        current += s;
      }
    }
  }
  void write(int l, int r){
    for(int i = l; i <= r; ++i){
      ask(i, i);
      int c = 0;
      for(int j = 0; j < 26; ++j){
        if(answer.a[j] > 0){
          c = j;
        }
      }
      printf("%c", char(c + 'a'));
    }
  }
}smt;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  smt.init();
  scanf("%d%d%s", &n, &m, arr + 1);
  for(int i = 1; i <= n; ++i){
    smt.upd(1, 1, n, i, i, arr[i] - 'a');
  }
  while(m--){
    int l, r, t;
    scanf("%d%d%d", &l, &r, &t);
    smt.update(l, r, t);
  }
  smt.write(1, n);
  return 0;
}