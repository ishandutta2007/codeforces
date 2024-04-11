#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int pos[N];
ll cost[N];

struct Node{
  ll value;
  ll lazy;
};

Node Tree[N * 4 + 512];

void push(int node, int cl, int cr){
  Tree[node].value += Tree[node].lazy;
  if(cl != cr){
    Tree[node * 2].lazy += Tree[node].lazy;
    Tree[node * 2 + 1].lazy += Tree[node].lazy;
  }
  Tree[node].lazy = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, int v){
  push(node, cl, cr);
  
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl && cr <= tr){
    Tree[node].lazy = v;
    push(node, cl, cr);
    return ;
  }
  int mid = (cl + cr) / 2;
  upd(node * 2, cl, mid, tl, tr, v);
  upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
  Tree[node].value = min(Tree[node * 2].value, Tree[node * 2 + 1].value);
}

ll ask(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl)
    return (ll)1e18;
  if(cl > tr)
    return (ll)1e18;
  if(cl >= tl && cr <= tr){
    return Tree[node].value;
  }
  int mid = (cl + cr) / 2;
  return min(ask(node * 2, cl, mid, tl, tr), ask(node * 2 + 1, mid + 1, cr, tl, tr));
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int p;
  for(int i = 1; i <= n; i ++ ){
    cin >> p;
    pos[p] = i;
  }
  for(int i = 1; i <= n; i ++ ){
    cin >> cost[i];
    if(i < n)upd(1, 1, n, i+1, n, cost[i]);
  }
  ll res = ask(1, 1, n, 2, n);  
  for(int i = 1; i <= n; i ++ ){
    upd(1, 1, n, 1, pos[i], +cost[pos[i]]);
    if(pos[i] + 1 <= n)upd(1, 1, n, pos[i] + 1, n, -cost[pos[i]]);
    res = min(res, ask(1, 1, n, 2, n));
  }
  cout << res;
  return 0;
}