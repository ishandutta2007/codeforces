#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;

int L[N], R[N];

int tree[2 * N + 512];

int sz;
void upd(int a, int b){
  a += sz;
  tree[a]+=b;
  a/=2;
  while(a > 0){
    tree[a]=tree[a*2]+tree[a*2+1];
    a/=2;
  }
}

int qry(int l, int r){
  l += sz;
  r += sz;
  int tot = 0;
  while(l <= r){
    if(l%2==1) tot += tree[l++];
    if(r%2==0) tot += tree[r--];
    l/=2;
    r/=2;
  }
  return tot;
}

vector<int> occ[N];
int pv[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  sz = N-1;
  vector<int> ord;
  int a;
  for(int i = 1; i <= n; i ++ )
    L[i] = R[i] = i;
  for(int i = 0 ; i < m; i ++ ){
    cin >> a;
    occ[a].push_back(i);
    ord.push_back(a);
    L[a] = 1;
  }
  for(int i = 0 ; i < N ; i ++ )
    pv[i] = -1;
  int f;
  for(int i = 0 ; i < m ; i ++ ){
    if(pv[ord[i]] == -1){
      f = ord[i] + qry(ord[i] + 1, n);
      R[ord[i]] = max(R[ord[i]], f);
      upd(ord[i],+1);
      pv[ord[i]] = i;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    if(pv[i] == -1){
      R[i] = max(R[i], i+qry(i+1,n));
    }
  }
  for(int i = 0 ; i < 2 * N + 512; i ++ )
    tree[i] = 0;
  for(int i = 0 ; i < N ; i ++ )
    pv[i] = -1;
  for(int i = 0 ; i < m ; i ++ ){
    if(pv[ord[i]] != -1){
      R[ord[i]] = max(R[ord[i]], 1+qry(pv[ord[i]]+1, i - 1));
      upd(i, +1);
      upd(pv[ord[i]], -1);
    }
    else{
      upd(i, +1);
    }
    pv[ord[i]] = i;
  }
  for(int i = 0 ; i < N ; i ++ )
    pv[i] = -1;
  int shit = 0;
  for(int i = m - 1; i >= 0 ; i -- ){
    if(pv[ord[i]] == -1){
      R[ord[i]]=max(R[ord[i]],shit+1);
      pv[ord[i]] = 1;
      shit++;
    }
  }
  for(int i = 1; i <= n; i ++ )
    cout << L[i] << " " << R[i] << "\n";
  return 0;
}