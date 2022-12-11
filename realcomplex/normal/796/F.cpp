#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;

int tree[N * 4 + 512];
int p[N];
int ans[N];

void push(int node, int cl, int cr){
  if(cl != cr){
    tree[node * 2] = min(tree[node], tree[node * 2]);   
    tree[node * 2 + 1] = min(tree[node], tree[node * 2 + 1]);
  }    
}

void upd(int node, int cl, int cr, int tl, int tr, int v){
  push(node, cl, cr);
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl && cr <= tr){
    tree[node] = min(tree[node], v);
    push(node, cl, cr);
    return;
  }
  int mid = (cl + cr) / 2;
  upd(node * 2, cl, mid, tl, tr, v);
  upd(node * 2 + 1, mid + 1, cr, tl, tr, v);  
}

int ask(int node, int cl, int cr, int idx){
  push(node, cl, cr);
  if(cl == cr)
    return tree[node];
  int mid = (cl + cr) / 2;
  if(mid >= idx)
    return ask(node * 2, cl, mid, idx);
  else
    return ask(node * 2 + 1, mid + 1, cr, idx);
}

set<int> ch[N];
int high[N];

int tt[N * 2 + 512];

int lim;

void upd(int idx, int p){
  idx += lim;
  tt[idx] = p;
  idx /= 2;
  while(idx > 0){
    tt[idx] = max(tt[idx * 2], tt[idx * 2 + 1]);
    idx /= 2;
  }
}

int qry(int l, int r){
  l += lim;
  r += lim;
  int res = -1;
  while(l <= r){
    if(l % 2 == 1) res = max(res, tt[l ++ ]);
    if(r % 2 == 0) res = max(res, tt[r -- ]);
    l /= 2;
    r /= 2;
  }
  return res;
}

set<int> relax;

int main(){
  fastIO;
  for(int i = 0 ; i < N * 4 + 512; i ++ ){
    tree[i] = (int)1e9 + 1;
  }
  for(int i = 0 ; i < N * 2 + 512; i ++ ){
    tt[i] = -1;
  }
  int n, m;
  cin >> n >> m;
  lim = n + 1;
  for(int i = 1; i <= n; i ++ ){
    p[i] = -1;
    high[i] = (int)1e9 + 1;
  }
  int ty[m], l[m], r[m], x[m];
  int qq;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> ty[i];
    if(ty[i] == 1){
      cin >> l[i] >> r[i] >> x[i];
      qq = qry(l[i], r[i]);
      if(qq == x[i]){
        relax.insert(x[i]);
      }
      upd(1, 1, n, l[i], r[i], x[i]);
    }
    else{
      cin >> l[i] >> x[i];
      if(p[l[i]] == -1){
        high[l[i]] = ask(1, 1, n, l[i]);
      }
      p[l[i]] = x[i];
      upd(l[i], x[i]);
    }
  }
  vector<pii> ids;
  for(int i = 1; i <= n; i ++ ){
    if(p[i] == -1){
      high[i] = ask(1, 1, n, i);
    }
    ids.push_back(mp(high[i], i));
    ans[i] = -1;
  }
  sort(ids.begin(), ids.end());
  int mx = 0;
  int z;
  for(int i = (int)ids.size() - 1 ; i >= 0 ; i -- ){
    if(!relax.count(ids[i].fi) && ids[i].fi != (int)1e9 + 1){
      mx |= ids[i].fi;
      relax.insert(ids[i].fi);
      ans[ids[i].se] = ids[i].fi;
    }
  }
  for(int i = (int)ids.size() - 1; i >= 0 ; i -- ){
    if(ans[ids[i].se] == -1){
      ans[ids[i].se] = 0;
      ids[i].fi = min(ids[i].fi, (int)1e9); 
      for(int j = 30 ; j >= 0 ; j -- ){
        if((mx & (1 << j))) continue;
        if((ans[ids[i].se] | (1 << j)) <= ids[i].fi){
          ans[ids[i].se] |= (1 << j);
          mx |= (1 << j);
        }
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    upd(i, ans[i]);
  }
  for(int q = 0; q < m ; q ++ ){
    if(ty[q] == 2){
      upd(l[q], x[q]);
    }
    else{
      if(qry(l[q], r[q]) != x[q]){
        cout << "NO\n";
        return 0;
      }
    }
  }
  // lol this is O(N log N)
  cout << "YES\n";
  for(int i = 1; i <= n; i ++ )
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}