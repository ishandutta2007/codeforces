#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)2e5 + 9;

int lf[N], rf[N];
int arr[N];

vector<int> L[N];


int T;
int tree[N * 2];

void upd(int ix, int t){
  ix += T;
  if(t == 0)
    t = 1239124;
  tree[ix] = t;
  ix /= 2;
  while(ix > 0){
    tree[ix] = min(tree[ix * 2], tree[ix * 2 + 1]);
    ix /= 2;
  }
}

int ask(int l, int r){
  l += T;
  r += T;
  int ans = (int)1e9;
  while(l <= r){
    if(l%2==1){
      ans = min(ans, tree[l]);
      l ++ ;
    }
    if(r%2==0){
      ans = min(ans, tree[r]);
      r -- ;
    }
    l/=2, r/=2;
  }
  return ans;
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  T = n;
  for(int i = 0;i < n;i ++ ){
    cin >> arr[i];
    L[arr[i]].push_back(i);
    lf[i] = arr[i];
    rf[i] = arr[i];
  }
  if(L[q].empty()){
    if(!L[0].empty()){
      int y = L[0].back();
      arr[y] = q;
      lf[y] = arr[y];
      rf[y] = arr[y];
      upd(y, q);
      L[q].push_back(y);
    }
    else{
      cout << "NO\n";
      return 0;
    }
  }
  for(int i = n-2;i >= 0;i -- ){
    if(rf[i] == 0)
      rf[i] = rf[i + 1];
  }
  for(int i = 1;i < n;i ++ ){
    if(lf[i] == 0)
      lf[i] = lf[i - 1];
  }
  for(int i = 0;i < n;i ++ )
    upd(i, arr[i]);
  for(int i = q;i >= 1;i -- ){
    for(int j = 1;j < L[i].size(); j ++ ){
      if(L[i][j] - L[i][j - 1] >= 2){
        if(ask(L[i][j - 1] + 1, L[i][j] - 1) < i){
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  for(int i = 0;i < n;i ++ ){
    cout << max(lf[i], rf[i]) << " ";
  }
  return 0;
}