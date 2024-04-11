#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e6 + 10;
struct Node{
  ll cnt;
  ll sum;
};

Node T[N * 4 + 512];

void upd(int node, int cl, int cr, int pos, int v){
  T[node].cnt += v;
  T[node].sum += v * pos;
  if(cl==cr)
    return;
  int mid = (cl + cr) / 2;
  if(mid >= pos)
    upd(node * 2, cl, mid, pos, v);
  else
    upd(node * 2 + 1, mid + 1, cr, pos, v);
}

Node ask(int node, int cl, int cr, int tl, int tr){
  if(cr < tl)
    return {0ll,0ll};
  if(cl > tr)
    return {0ll,0ll};
  if(cl >= tl && cr <= tr){
    return T[node];
  }
  int mid = (cl + cr) / 2;
  Node li = ask(node * 2, cl, mid, tl, tr);
  Node ri = ask(node * 2 + 1, mid + 1, cr, tl, tr);
  return {li.cnt + ri.cnt, li.sum + ri.sum};
}

vector<int> Z(string t){
  int h = t.size();
  vector<int> sol(h);
  sol[0]=0;
  int l = 0, r = 0;
  for(int i = 1; i < h ; i ++ ){
    if(i <= r){
      sol[i]=min(sol[i-l],r-i+1);
    }
    while(i + sol[i] < h && t[i + sol[i]] == t[sol[i]])
      sol[i] ++ ;
    if(i + sol[i] - 1 > r){
      l = i;
      r = i + sol[i] - 1;
    }
  }
  return sol;
}


int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  string a, b, t;
  cin >> a >> b >> t;
  string qq = t + '#' + a;
  vector<int> A = Z(qq);
  vector<int> Ai,Bi;
  for(int i = m + 1; i < A.size(); i ++ ){
    A[i] = min(A[i], m - 1);
    Ai.push_back(A[i]);
  }
  reverse(t.begin(), t.end());
  reverse(b.begin(), b.end());
  qq = t + '#' + b;
  A = Z(qq);
  for(int i = A.size() - 1; i >= 0 ; i -- ){
    if(qq[i] == '#') break;
    Bi.push_back(A[i]);
  }
  for(auto &x : Bi){
    x = max(0, m - x - 1);
  }
  int p = (int)n - 1;
  ll ans = 0;
  for(int i = n - 1; i >= 0 ; i -- ){
    upd(1, 0, m, Bi[i], +1);
    while(p - i + 1 >= m){
      upd(1, 0, m, Bi[p], -1);
      p -- ;
    }
    Node cur = ask(1, 0, m, 0, Ai[i]);
    ans += cur.cnt * 1ll * Ai[i];
    ans -= cur.sum;
  }
  cout << ans << "\n";
  return 0;
}