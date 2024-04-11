#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int tree[N * 4 + 512];

void inc(int node, int cl, int cr, int p){
  tree[node]++;
  if(cl==cr)
    return;
  int mid = (cl + cr) / 2;
  if(mid >= p)
    inc(node * 2, cl, mid, p);
  else
    inc(node * 2 + 1, mid + 1, cr, p);
}

int ask(int node, int cl, int cr, int rq){
  if(cl==cr)
    return cl;
  int mid = (cl + cr) / 2;
  if(tree[node*2] >= rq){
    return ask(node*2,cl,mid,rq);
  }
  else{   
    return ask(node*2+1,mid+1,cr,rq-tree[node*2]);
  }
}

vector<pii> qq[N];
int res[N];
int a[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> ind;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    ind.push_back(mp(a[i],-i));
  }
  sort(ind.begin(), ind.end());
  int q;
  cin >> q;
  int k, p;
  for(int i = 0 ;i  < q; i++ ){
    cin >> k >> p;
    qq[k].push_back(mp(p,i));
  }
  int comp = 1;
  for(int j = n - 1; j >= 0 ; j -- ){
    inc(1, 1, n, -ind[j].se);
    for(auto x : qq[comp]){
      res[x.se] = a[ask(1, 1, n, x.fi)];
    }
    comp ++ ;
  }
  for(int i = 0 ;i < q; i ++ )
    cout << res[i] << "\n";
  return 0;
}