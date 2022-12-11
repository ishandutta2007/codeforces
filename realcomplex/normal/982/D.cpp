#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

const int N = 123456;

struct Union{
  int p[N];
  int sz[N];
  void init(){
    for(int i = 0;i < N;i ++ ){
      sz[i] = 0;
      p[i] = i;
    }
  }
  int ffind(int a){
    while(p[a] != a)
      a = p[a];
    return a;
  }
  void unite(int a, int b){
    a = ffind(a);
    b = ffind(b);
    if(sz[a] > sz[b])
      swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
  }
};

multiset<int>sizes;

bool check(){
  auto X = sizes.begin();
  auto Y = sizes.end();
  Y -- ;
  return (*X) == (*Y);
}

void remove(int ss){
  sizes.erase(sizes.find(ss));
}

void add(int ss){
  sizes.insert(ss);
}

Union segments;

int main(){
  fastIO;
  segments.init();
  int n;
  cin >> n;
  pii a[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i].fi;
    a[i].se = i+2;
  }
  sort(a, a + n);
  int pos;
  int tl, tr;
  int ans = 0;
  int segm = 0;
  for(int i = 0;i < n;i ++ ){
    pos = a[i].se;
    segments.sz[pos] = 1;
    tl = segments.ffind(pos - 1);
    tr = segments.ffind(pos + 1);
    if(segments.sz[tl] != 0){
      remove(segments.sz[tl]);
      segments.unite(tl, pos);
    }
    if(segments.sz[tr] != 0){
      remove(segments.sz[tr]);
      segments.unite(tr, pos);
    }
    pos = segments.ffind(pos);
    add(segments.sz[pos]);
    if(check()){
      if(sizes.size() > segm){
        ans = a[i].fi + 1;
        segm = sizes.size();
      }
    }
  }
  cout << ans << "\n";
  return 0;
}