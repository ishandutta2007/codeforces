#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e5;
const int DV = 11;
int BLOCK;

int decomp[N][DV][DV][4];

map<char, int> cmp;
int dna[N];
vector<int> infect;

int Calc(int l, int r){
  int ix = l;
  int ans = 0;
  int mod = infect.size();
  int p = 0;
  while(ix % BLOCK != 0 and ix <= r){
    ans += infect[p] == dna[ix];
    p ++ ;
    p %= mod;
    ix ++ ;
  }
  int bl = ix/BLOCK;
  while(ix + BLOCK - 1 <= r){
    for(int j = 0;j < mod; j ++ ){
      ans += decomp[bl][mod][(j + l) % mod][infect[j]];
    }
    ++bl;
    p += BLOCK;
    p %= mod;
    ix += BLOCK;
  }
  while(ix <= r){
    ans += infect[p] == dna[ix];
    p ++ ;
    p %= mod;
    ix ++ ;
  }
  return ans;
}

int main(){
  fastIO;
  cmp['A'] = 0;
  cmp['T'] = 1;
  cmp['G'] = 2;
  cmp['C'] = 3;
  string s;
  int n;
  cin >> s;
  n = s.size();
  BLOCK = int(sqrt(n));
  for(int i = 0;i < n; i ++ ){
    dna[i] = cmp[s[i]];
  }
  int cur;
  for(int i = 0;i < n; i ++ ){
    cur = i/BLOCK;
    for(int j = 1; j < DV; j ++ ){
      decomp[cur][j][i%j][dna[i]] ++ ;
    }
  }
  int q;
  cin >> q;
  int ty;
  char chng;
  int pos;
  int l, r;
  string e;
  int nx;
  int ans = 0;
  for(int query = 0; query < q; query ++ ){
    cin >> ty;
    if(ty == 1){
      cin >> pos >> chng;
      --pos;
      nx = cmp[chng];
      cur = pos/BLOCK;
      for(int j = 1;j < DV; j ++ ){
        decomp[cur][j][pos%j][dna[pos]] -- ;
      }
      dna[pos] = nx;
      for(int j = 1;j < DV; j ++ ){
        decomp[cur][j][pos%j][dna[pos]] ++ ;
      }
    }
    else{
      cin >> l >> r >> e;
      infect.clear();
      for(char xx : e)
        infect.push_back(cmp[xx]);
      --l, --r;
      cout << Calc(l, r) << "\n";
    }
  }
  return 0;
}