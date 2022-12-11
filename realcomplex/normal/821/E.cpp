#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int)1e9 + 7;

void add(int &a, int b){
  a += b;
  if(a >= MOD) a -= MOD;
}

int mult(int a, int b){
  return (a * 1ll * b) % MOD;
}

vector<vector<int>> mult(vector<vector<int>> A, vector<vector<int>> B){
  int m = A[0].size();
  int n = A.size();
  int k = B[0].size();
  vector<vector<int>> C(n);
  for(int i = 0 ; i < n; i ++ ){
    C[i].resize(k);
    for(int j = 0 ; j < k ; j ++ ){
      for(int p = 0 ; p < m ; p ++ ){
        add(C[i][j], mult(A[i][p],B[p][j]));
      }
    }
  }
  return C;
}

vector<vector<int>> pwr(vector<vector<int>> A, ll k){
  if(k == 0){
    vector<vector<int>> ide(A.size());
    for(int i = 0; i < A.size(); i ++ ){
      ide[i].resize(A.size());
      ide[i][i] = 1;
    }
    return ide;
  }
  vector<vector<int>> p = pwr(A,k/2);
  p = mult(p, p);
  if((k&1)) p = mult(p, A);
  return p;
}

int main(){
  fastIO;
  int n;
  ll k;
  cin >> n >> k;
  int c;
  ll a, b;
  vector<int> las = {1};
  for(int i = 0 ; i < n; i ++ ){
    cin >> a >> b >> c;
    b = min(b, k);
    while(las.size() <= c) las.push_back(0);
    while(las.size() > c+1) las.pop_back();
    vector<vector<int>> mtx(c+1);
    for(int i = 0 ; i < c + 1; i ++ ){
      mtx[i].resize(c + 1);
      mtx[i][i] = 1;
      if(i>0)mtx[i][i-1] = 1;
      if(i+1<c+1)mtx[i][i+1]=1;
    }
    mtx = pwr(mtx,b-a);
    vector<vector<int>> t;  
    t.push_back(las);
    t = mult(t, mtx);
    las = t[0];
  }
  int ans = 0;
  cout << las[0] << "\n";
  return 0;
}