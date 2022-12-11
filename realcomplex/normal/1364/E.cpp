#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> cand;

int n;

int gen(){
  return ((int)rng() % n + n) % n;
}


const int N = 2050;
int answ[N][N];
int qq = 0;

int lim = 2200;

vector<pii> tit;

int query(int a, int b){ 
  if(answ[a][b] != -1)
    return answ[a][b];
  qq ++ ;
  cout << "? " << a + 1 << " " << b + 1 << "\n";
  fflush(stdout);
  int res;
  cin >> res;
  answ[a][b]=res;
  answ[b][a]=res;
  tit.push_back(mp(a,b));
  return answ[a][b]=res;
}

int main(){
  cin >> n;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < n; j ++ ){
      answ[i][j] = -1;
    }
  }
  for(int i = 0 ; i < n; i ++ )
    cand.push_back(i);
  int p, q;
  for(int i = 0 ; i < 7500 ; i ++ ){
    p = gen();
    q = gen();
    swap(cand[p], cand[q]);
  }
  int f0, f1, f2;
  bool ok;
  bool can;
  int lay = 0;
  while(cand.size() > 1){
    vector<int> nw;
    int xi, yi;
    for(auto c : cand){
      ok = true;
      for(int i = 0 ; i < n; i ++ ){
        if(answ[c][i] == -1) continue;
        for(int j = 0 ; j < n; j ++ ){
          if(answ[i][j] == -1) continue;
          if((answ[c][i] & answ[i][j]) != answ[c][i]){
            ok = false;
          }
        }
      }
      
      if(!ok) continue;
      
      if(qq >= 1200){
        while(1){
          xi = (rng() % (int)tit.size()) % tit.size();
          yi = tit[xi].se;
          xi = tit[xi].fi;
          if(xi != c && yi != c) break;
        }
      }
      else{
        while(1){
          xi = gen();
          yi = gen();
          if(xi != yi && xi != c && yi != c) break;
        }
      }
      if(answ[c][xi] != -1) f0 = answ[c][xi];
      else if(answ[c][yi] != -1) f0 = answ[c][yi];
      else {
        f0 = query(c, xi);
      }
      f2 = query(xi, yi);
      if((f0 & f2) == f0){
        nw.push_back(c);
      }
    }
    cand = nw;
  }
  int cur = cand[0];
  vector<int> res;
  for(int i = 0 ; i < n; i ++ ){
    if(i == cur){
      res.push_back(0);
    }
    else{
      res.push_back(query(cur,i));
    }
  }
  cout << "! ";
  for(auto x : res)
    cout << x << " ";
  cout << "\n";
  fflush(stdout);
  return 0;
}