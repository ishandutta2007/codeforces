#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int M = (int)2e6 + 9; // whatever idc

int cnt;
int idx[M];

vector<pii> T[M];
ll dd[M];

bool dir;

void build(int node, int cl, int cr){
  idx[node] = ++cnt;
  if(cl==cr){
    if(!dir)T[idx[node]].push_back(mp(cl, 0));
    else T[cl].push_back(mp(idx[node], 0));
    return;
  }
  int mid = (cl + cr) / 2;
  build(node * 2, cl, mid);
  build(node * 2 + 1, mid + 1, cr);
  if(!dir){
    T[idx[node]].push_back(mp(idx[node * 2], 0));
    T[idx[node]].push_back(mp(idx[node * 2 + 1], 0));
  }
  else{
    T[idx[node * 2]].push_back(mp(idx[node], 0));
    T[idx[node * 2 + 1]].push_back(mp(idx[node], 0));
  }
}

void add(int node, int cl, int cr, int tl, int tr, int v, int w){
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl && cr <= tr){
    if(!dir)T[v].push_back(mp(idx[node], w));
    else T[idx[node]].push_back(mp(v,w));
    return;
  }
  int mid = (cl + cr) / 2;
  add(node * 2, cl, mid, tl, tr, v, w);
  add(node * 2 + 1, mid + 1, cr, tl, tr, v, w);
}

int main(){
  fastIO;
  int n, q, st;
  cin >> n >> q >> st;
  cnt = n;
  int ty[q],nd[q], l[q], r[q], w[q];
  for(int i = 0 ; i < q; i ++ ){
    cin >> ty[i];
    if(ty[i] == 1){
      ty[i]=2;
      cin >> nd[i] >> l[i] >> w[i];
      r[i] = l[i];
    }
    else{
      cin >> nd[i] >>  l[i] >> r[i] >> w[i];
    }
  }

  dir = false;
  build(1, 1, n);
  for(int i = 0 ; i < q; i ++ ){
    if(ty[i] == 2){
      add(1, 1, n, l[i], r[i], nd[i], w[i]);
    }
  }
  
  dir = true;
  
  build(1, 1, n);
  for(int i = 0 ; i < q; i ++ ){
    if(ty[i] == 3){
      add(1, 1, n, l[i], r[i], nd[i], w[i]);
    }
  }
  for(int i = 1; i <= cnt; i ++ ){
    dd[i] = (ll)1e15;
  }
  dd[st] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> ff;
  ff.push(mp(0ll, st));
  int node;
  ll di;
  while(!ff.empty()){
    node = ff.top().se;
    di = ff.top().fi;
    ff.pop();
    if(dd[node] != di) continue;
    for(auto x : T[node]){
      if(dd[node] + x.se < dd[x.fi]){
        dd[x.fi] = dd[node] + x.se;
        ff.push(mp(dd[x.fi], x.fi));
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    if(dd[i] == (ll)1e15)
      cout << -1 << " ";
    else
      cout << dd[i] << " ";
  }
  cout << "\n";
  return 0;
}