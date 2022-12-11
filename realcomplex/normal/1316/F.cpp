#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
const int M = (int)6e5 + 9;
const int MOD = (int)1e9 + 7;

int powr(int n, int k){
  if(k == 0)
    return 1;
  int p = powr(n,k/2);
  p = (p * 1ll * p) % MOD;
  if(k % 2 == 1) p = (p * 1ll * n) % MOD;
  return p;
}

int a[N];
int pi[N], vi[N];
int pwr[N];

vector<pii> it;

struct Node{  
  int res;
  int sz;
  int suml;
  int sumr;
};

Node T[M * 4 + 512];

Node unite(Node A, Node B){
  if(B.sz == 0) return A;
  if(A.sz == 0) return B;
  Node p;
  p.res = ((A.res*1ll*pwr[B.sz])%MOD+(B.res*1ll*pwr[A.sz])%MOD)%MOD;
  p.res = (p.res + (A.suml * 1ll * B.sumr) % MOD) % MOD;
  p.sz = (A.sz + B.sz) % MOD;
  p.suml = (A.suml + (B.suml * 1ll * pwr[A.sz]) % MOD) % MOD;
  p.sumr = (B.sumr + (A.sumr * 1ll * pwr[B.sz]) % MOD) % MOD;
  return p;
}

void upd(int node, int cl, int cr, int pos, int keep){
  if(cl == cr){
    if(keep) T[node] = {0,1,it[cl].fi,it[cl].fi};
    else T[node] = {0,0,0,0};
    return ;
  }
  int mid = (cl + cr) / 2;
  if(mid >= pos)
    upd(node * 2, cl, mid, pos, keep);
  else
    upd(node * 2 + 1, mid + 1, cr, pos, keep);
  T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

int m;

int main(){
  fastIO;
  int n;
  cin >> n;
  pwr[0] = 1;
  for(int i = 1; i <= n; i ++ ){
    pwr[i] = (pwr[i-1] * 2ll) % MOD;
  }
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    it.push_back(mp(a[i],i));
  }
  int q;
  cin >> q;
  for(int i = 1; i <= q; i ++ ){
    cin >> pi[i] >> vi[i];
    it.push_back(mp(vi[i], pi[i]));
  }
  sort(it.begin(), it.end());
  it.resize(unique(it.begin(), it.end()) - it.begin());
  int m = it.size();
  int id;
  for(int i = 1 ; i <= n; i ++ ){
    id = lower_bound(it.begin(), it.end(), mp(a[i], i)) - it.begin();
    upd(1, 0, m - 1, id, 1);
  }
  cout << (T[1].res * 1ll * powr(pwr[n],MOD-2))%MOD << "\n";
  for(int i = 1; i <= q; i ++ ){
    id = lower_bound(it.begin(), it.end(), mp(a[pi[i]], pi[i])) - it.begin();
    upd(1, 0, m - 1, id, 0);
    a[pi[i]] = vi[i];
    id = lower_bound(it.begin(), it.end(), mp(a[pi[i]], pi[i])) - it.begin();
    upd(1, 0, m - 1, id, 1);
    cout << (T[1].res * 1ll * powr(pwr[n],MOD-2))%MOD << "\n";
  }
  return 0;
}