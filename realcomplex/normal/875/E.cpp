#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 15;
int n;
int x[N];
int id[N];
vector<pii> cor;

int ab(int i, int j){
  return abs(x[i]-x[j]);
}

struct Node{
  int lazy;
  int value;
};

Node tree[2 * N + 512];
int lft[2 * N + 512];
int rft[2 * N + 512];
int cnt=0;

void build(int node, int cl, int cr){
  if(cl==cr)
    return;
  int mid = (cl + cr) / 2;
  lft[node] = ++cnt;
  rft[node] = ++cnt;
  build(lft[node], cl, mid);
  build(rft[node], mid+1,cr);
}

void push(int node, int cl, int cr){
  if(tree[node].lazy != -1){
    tree[node].value = tree[node].lazy;
    if(cl != cr){
      tree[lft[node]].lazy = tree[node].lazy;
      tree[rft[node]].lazy = tree[node].lazy;
    }
    tree[node].lazy=-1;
  }
}

void upd(int node, int cl, int cr, int tl, int tr, int st){
  push(node, cl, cr);
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl && cr <= tr){
    tree[node].lazy = st;
    push(node, cl, cr);
    return;
  }
  int mid = (cl + cr) >> 1;
  upd(lft[node], cl, mid, tl, tr, st);
  upd(rft[node], mid + 1, cr, tl, tr, st);
  tree[node].value = (tree[lft[node]].value | tree[rft[node]].value);
}

int ask(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl)
    return 0;
  if(cl > tr)
    return 0;
  if(cl >= tl && cr <= tr){
    return tree[node].value;
  }
  int mid = (cl + cr) >> 1;
  return (ask(lft[node], cl, mid, tl, tr) | ask(rft[node], mid + 1, cr, tl, tr));
}

bool check(int C){
  upd(0,0,n-1,0,n-1,0);
  upd(0,0,n-1,id[0],id[0],(C>=ab(0,1)));
  int nx;
  int las;
  for(int j = 2; j < n; j ++ ){
    if(ab(j,j-1) > C || tree[0].value == 0)
      las = 0;
    else
      las = 1;
    
    nx = x[j] + C;
    nx = upper_bound(cor.begin(), cor.end(), mp(nx+1,-1)) - cor.begin();
    if(nx < n)
      upd(0, 0, n - 1, nx, n - 1, 0);
    nx = x[j] - C;
    nx = lower_bound(cor.begin(), cor.end(), mp(nx,-1)) - cor.begin();
    --nx;
    if(nx >= 0)
      upd(0, 0, n - 1, 0, nx, 0);
    upd(0, 0, n - 1, id[j-1],id[j-1],las);
  }
  return tree[0].value;
}

int main(){
  fastIO;
  for(int i = 0 ; i < 2 * N + 512; i ++ )
    tree[i] = {-1, 0};
  cin >> n;
  n += 2;
  build(0,0,n-1);
  for(int i = 0 ; i < n; i ++ ){
    cin >> x[i];
    cor.push_back(mp(x[i],i));
  }
  sort(cor.begin(), cor.end());
  for(int i = 0 ; i < n; i ++ ){
    id[cor[i].se] = i;
  }
  int lf = 0, rf = (int)1e9 + 41;
  int md;
  while(lf < rf){
    md = (lf + rf) / 2;
    if(check(md))
      rf = md;
    else
      lf = md + 1;
  }
  cout << rf;
  return 0;
}