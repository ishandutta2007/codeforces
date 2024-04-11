#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int query(string t){
  cout << t << "\n";
  fflush(stdout);
  int r;
  cin >> r;
  if(r == 0)
    exit(0);
  return r;
}

int main(){
  string q;
  int N = 300;
  for(int t = 0; t < N ; t ++ )
    q.push_back('a');
  int ca = N - query(q);
  q.clear();
  for(int t = 0 ; t < N; t ++ )
    q.push_back('b');
  int cb = N - query(q);
  string f;
  for(int i = 0 ; i < ca + cb; i ++ ){
    f.push_back('a');
  }
  int las = cb;
  int x;
  int qa = 0, qb = 0;
  for(int i = 0 ; i < ca + cb - 1; i ++ ){
    f[i] = 'b';
    x = query(f);
    f[i] = 'a';
    if(x < las){
      f[i] = 'b';
      las = x;
    }
    if(f[i] == 'a')
      qa ++ ;
    else
      qb ++ ;
  }
  if(qb < cb)
    f[ca + cb - 1] = 'b';
  query(f);
  return 0;
}