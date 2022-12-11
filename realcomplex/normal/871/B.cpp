#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int ask(int i, int j){
  cout << "? " << i << " " << j << "\n";
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}


const int N = 5000;
int b[N];
int p[N];
int bc[N];

int main(){
  //fastIO;
  int n;
  cin >> n;
  for(int i = 1 ; i < n; i ++ ){
    b[i] = ask(0,i);
    p[i] = ask(i,0);
  }
  int x = ask(0,0);
  b[0]=x;
  p[0]=x;
  for(int i = n - 2; i >= 0 ; i -- ){
    b[i + 1] ^= b[i];
    p[i + 1] ^= p[i];
  }
  vector<int> per;
  int cx;
  bool valid;
  int cnt = 0;
  vector<int> ret = {};
  for(int y = 0 ; y < n; y ++ ){
    valid = true;
    per.clear();
    per.push_back(y);
    cx = y;
    for(int q = 0; q < n; q ++ ) bc[q] = -1;
    for(int t = 1; t < n; t ++ ){
      cx ^= p[t];
      per.push_back(cx);
    }
    for(int q = 0 ; q < n; q ++ ){
      if(per[q] >= n) valid = false;
      else bc[per[q]]=q;
    }
    for(int q = 0 ; q < n; q ++ ){
      if(bc[q] == -1) valid = false;
    }
    if(valid){
      for(int q = 0; q + 1 < n; q ++ ){
        if((bc[q] ^ bc[q + 1]) != b[q + 1]) valid = false;
      }
      if((bc[0]^per[0]) != x) valid = false;
    }
    if(valid){
      ret = per;
      cnt ++ ;
    }
  }
  cout << "!\n";
  cout << cnt << "\n";
  for(auto x : ret)
    cout << x << " ";
  cout << "\n";
  fflush(stdout);
  return 0;
}