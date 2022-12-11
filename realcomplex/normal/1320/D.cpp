#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool is_pr(ll x){
  if(x % 2 == 0) return false;
  for(ll i = 3 ; i * i <= x; i += 2 ){
    if(x % i == 0)
      return false;
  }
  return true;
}

ll gen_mod(){
  ll x = ((ll)rng() % (ll)1e14 + (ll)1e14 + (ll)5e13) % (ll)1e14;
  while(!is_pr(x)) x ++ ;
  return x;
}

const int N = (int)2e5 + 10;
const ll MOD = (ll)1e9 + 9;
const ll P = 7;

ll powr(ll n, ll k){  
  if(k==0)return 1ll;
  ll p = powr(n,k/2);
  p=(p*1ll*p)%MOD;
  if(k % 2 == 1)
    p=(p*1ll*n)%MOD;
  return p;
}

ll inv;

ll pwr[N];
int bit[N];

struct Node{
  int li;
  int ri;
  ll hsh;
  int len;
  int bitl;
  int bitr;
};

Node T[N * 4 + 512];

Node unite(Node A, Node B){
  if(A.len==0)return B;
  if(B.len==0)return A;
  Node res;
  res.li = A.li;
  res.ri = B.ri;
  res.len = A.len + B.len;
  res.bitl = A.bitl;
  res.bitr = B.bitr;
  if(A.bitr == 1 && B.bitl == 1){
    A.hsh = (A.hsh - pwr[A.len] + MOD) % MOD;
    B.hsh = (B.hsh - pwr[1] + MOD) % MOD;
    B.hsh = (B.hsh * 1ll * inv) % MOD;
    if(A.len == 1) res.bitl=0;
    if(B.len == 1) res.bitr=0;
    A.len -- ;
    B.len -- ;
    res.len -= 2;
  }
  
  res.hsh = (A.hsh + (B.hsh * 1ll * pwr[A.len]) % MOD) % MOD; 
  return res;
  
}

void build(int node, int cl, int cr){
  if(cl == cr){
    T[node] = {cl, cr, bit[cl]*1ll*pwr[1],1,bit[cl],bit[cl]};
    return;
  }
  int mid = (cl + cr) / 2;
  build(node * 2, cl, mid);
  build(node * 2 + 1, mid + 1, cr);
  T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

Node ask(int node, int cl, int cr, int tl, int tr){
  if(cl > tr) return {-1,-1,0,0,0,0};
  if(cr < tl) return {-1,-1,0,0,0,0};
  if(cl >= tl && cr <= tr){
    return T[node];
  }
  int mid = (cl + cr) / 2;
  return unite(ask(node * 2, cl, mid, tl, tr),
  ask(node * 2 + 1, mid + 1, cr, tl, tr));
}

int main(){
  fastIO;
  inv = powr(P,MOD-2);
  pwr[0]=1ll;
  for(int i = 1; i < N ; i ++ ){
    pwr[i]=(pwr[i-1]*1ll*P)%MOD;
  }
  int n;
  cin >> n;
  char f;
  for(int i = 1; i <= n; i ++ ){
    cin >> f;
    bit[i]=f-'0';
  }
  build(1, 1, n);
  int q;
  cin >> q;
  int l1, l2, len;
  int r1, r2;
  Node c1, c2;
  for(int i = 0 ; i < q; i ++ ){
    cin >> l1 >> l2 >> len;
    r1 = l1 + len - 1;
    r2 = l2 + len - 1;
    c1 = ask(1, 1, n, l1, r1);
    c2 = ask(1, 1, n, l2, r2);
    if(c1.hsh == c2.hsh && c1.len == c2.len)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0; 
}