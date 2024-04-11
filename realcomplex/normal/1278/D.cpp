#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
int pi[N];
int sz[N];

int fin(int u){
  if(pi[u]==u)
    return u;
  return pi[u]=fin(pi[u]);
}

int cnt = 0;

bool unite(int a, int b){
  a=fin(a);
  b=fin(b);
  if(a==b)
    return false;
  cnt ++ ;
  if(sz[a] > sz[b])
    swap(a,b);
  sz[b] += sz[a];
  pi[a] = b;
  return true;
}

vector<pii> ins[2 * N];
vector<pii> er[2 * N];
vector<pii> tt[2 * N];


int main(){
  fastIO;
  int n;
  cin >> n;
  int l, r;
  for(int i = 1; i <= n; i ++ ){
    cin >> l >> r;
    ins[l].push_back(mp(i,r));
    er[r].push_back(mp(i, l));
    pi[i]=i;
    sz[i]=1;
  }
  set<pii> el;
  
  for(int i = 1; i <= 2 * n; i ++ ){
    for(auto x : ins[i]){
      el.insert(mp(i, fin(x.fi)));
      tt[x.se].push_back(mp(i, fin(x.fi)));
    }
    for(auto p : tt[i]){
      el.erase(p);
    }
    for(auto p : er[i]){
      auto it = el.lower_bound(mp(p.se + 1, -1));
      while(it != el.end()){
        //cout << p.fi << " " << it->se << "\n";
        if(!unite(p.fi, it->se)){
          cout << "NO\n";
          return 0;
        }
        it++;
      }
    }
  }
  if(cnt == n - 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}