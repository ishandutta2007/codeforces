#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<pii> R[N];
int a[N], b[N];
int fa[N];
int pos[N];

pii tree[N * 4 + 512];

void upd(int node, int cl, int cr, int pos, int v){ 
  if(cl == cr){
    tree[node] = mp(v,pos);
    return ;
  }
  int mid = (cl + cr) / 2;
  if(mid >= pos)upd(node * 2, cl, mid, pos, v);
  else upd(node * 2 + 1, mid + 1, cr, pos, v);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

pii ask(int node, int cl, int cr, int tl, int tr){
  if(cr < tl || cl > tr) 
    return mp(-1,-1);
  if(cl >= tl && cr <= tr){
    return tree[node];
  }
  int mid = (cl + cr) / 2;
  return max(ask(node * 2, cl, mid, tl, tr),ask(node * 2 + 1, mid + 1, cr, tl, tr));
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i] >> b[i];
    R[a[i]].push_back(mp(b[i] + 1, i));
  }
  priority_queue<pii,vector<pii>,greater<pii>> ff;
  for(int i = 1; i <= n; i ++ ){
    for(auto x : R[i]){
      ff.push(x);
    }
    while(!ff.empty() && ff.top().fi <= i) ff.pop();
    if(ff.empty()){
      assert(0);
    }
    fa[ff.top().se] = i;
    pos[i] = ff.top().se;
    ff.pop();
  }
  pii chk;
  int wi = -1, wj = -1;
  for(int i = 1; i <= n; i ++ ){
    if(i > 1 && i > a[pos[i]]){
      chk = ask(1, 1, n, a[pos[i]], i - 1);
      if(chk.fi >= i){
        wi = pos[i];
        wj = pos[chk.se];
        break;
      }
    }
    upd(1, 1, n, i, b[pos[i]]);
  }
  if(wi == -1){
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ )
      cout << fa[i] << " ";
    cout << "\n";
  }
  else{
    cout << "NO\n";
    for(int i = 1; i <= n; i ++ )
      cout << fa[i] << " ";
    cout << "\n";
    swap(fa[wi], fa[wj]);
    for(int i = 1; i <= n; i ++ )
      cout << fa[i] << " ";
    cout << "\n";
  }
  return 0;
}