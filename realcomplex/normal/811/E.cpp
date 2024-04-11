#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int M = (int)1e6 + 9;

int a[10][N];
int idx[10][N];

int par[M];
vector<int> reset;
bool keep;
int fin(int x){
  if(keep)
    reset.push_back(x);
  if(x==par[x])
    return x;
  return par[x]=fin(par[x]);
}

bool unite(int a, int b){
  a=fin(a);
  b=fin(b);
  if(a==b)
    return false;
  par[a]=b;
  return true;
}

struct Node{
  vector<int> lf;
  vector<int> rf;
  vector<int> la;
  vector<int> ra;
  int cnt;
};

Node Tree[4 * N + 512];

int n;
void build(int node, int cl, int cr){
  if(cl==cr){
    for(int j = 0 ; j < n; j ++ ){
      Tree[node].lf.push_back(idx[j][cl]);
      Tree[node].rf.push_back(idx[j][cl]);
      Tree[node].la.push_back(a[j][cl]);
      Tree[node].ra.push_back(a[j][cl]);
      if(j > 0 && a[j][cl] == a[j-1][cl]){
        Tree[node].cnt ++ ;
        unite(idx[j][cl], idx[j-1][cl]);
      }
    }
    for(int i = 0 ; i < n ; i ++ ){
      Tree[node].lf[i] = fin(Tree[node].lf[i]);
      Tree[node].rf[i] = fin(Tree[node].rf[i]);
    }
    return;
  }
  int mid = (cl + cr) / 2;
  build(node * 2, cl, mid);
  build(node * 2 + 1, mid + 1, cr);
  Tree[node].cnt = Tree[node * 2].cnt + Tree[node * 2 + 1].cnt;
  Tree[node].la = Tree[node * 2].la;
  Tree[node].ra = Tree[node * 2 + 1].ra;
  Tree[node].lf = Tree[node * 2].lf;
  Tree[node].rf = Tree[node * 2 + 1].rf;
  for(int t = 0; t < n; t ++ ){
    if(Tree[node * 2].ra[t] == Tree[node * 2 + 1].la[t]){
      Tree[node].cnt += unite(Tree[node*2].rf[t], Tree[node*2+1].lf[t]);
    }
  }
  for(int i = 0 ; i < n ; i ++ ){
    Tree[node].lf[i] = fin(Tree[node].lf[i]);
    Tree[node].rf[i] = fin(Tree[node].rf[i]);
  }
  
}

Node cur;

void ask(int node, int cl, int cr, int tl, int tr){
  if(cr < tl) return;
  if(cl > tr) return;
  if(cl >= tl && cr <= tr){
    for(int i = 0 ; i < n; i ++ ){
      par[idx[i][cl]] = Tree[node].lf[i];
      par[idx[i][cr]] = Tree[node].rf[i];
      reset.push_back(idx[i][cl]);
      reset.push_back(idx[i][cr]);
    }
    if(cur.lf.empty()){
      cur = Tree[node];
    }
    else{
      cur.cnt += Tree[node].cnt;
      for(int i = 0 ; i < n; i ++ ){
        if(cur.ra[i] == Tree[node].la[i]){
          cur.cnt += unite(idx[i][cl-1],idx[i][cl]);
        }
      }
      cur.ra = Tree[node].ra;
      cur.rf = Tree[node].rf;
      for(int i = 0 ; i < n ; i ++ ){
        cur.lf[i] = fin(cur.lf[i]);
        cur.rf[i] = fin(cur.rf[i]);
      }
    }
    return;
  }
  int mid = (cl + cr) / 2;
  ask(node * 2, cl, mid, tl, tr);
  ask(node * 2 + 1, mid + 1, cr, tl, tr);
}

int main(){
  fastIO;
  for(int i = 0 ; i < M ;i ++ )
    par[i]=i;
  int m, q;
  cin >> n >> m >> q;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < m ; j ++ ){
      cin >> a[i][j];
      idx[i][j]=i*m+j;
    }
  }
  keep = false;
  build(1, 0, m - 1);
  keep = true;
  for(int i = 0 ; i < M ;i ++ )
    par[i]=i;
  int li, ri;
  cur ={{},{},{},{},0};
  for(int jj = 0 ; jj < q; jj ++ ){
    cin >> li >> ri;
    li -- ;
    ri -- ;
    cur = {{},{},{},{},0};
    ask(1, 0, m - 1, li, ri);
    cout << (ri - li + 1) * n - cur.cnt << "\n"; 
    for(auto x : reset)
      par[x]=x;
    reset.clear();
  }
  return 0;
}