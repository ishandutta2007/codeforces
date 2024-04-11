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

const int N = (int)1e6 + 9;

int n;
int tree[N * 2];

void upd(int ix){
  ix += n;
  tree[ix] = 1;
  ix /= 2;
  while(ix > 0){
    tree[ix] = tree[ix*2] + tree[ix * 2 + 1];
    ix /= 2;
  }
}

int ask(int li,int ri){
  li += n;
  ri += n;
  int rz = 0;
  while(li <= ri){
    if(li % 2 == 1){
      rz += tree[li];
      li ++ ;
    }
    if(ri % 2 == 0){
      rz += tree[ri];
      ri -- ;
    }
    li /= 2;
    ri /= 2;
  }
  return rz;
}

int main(){
  fastIO;
  cin >> n;
  int p;
  ll inv = 0;
  for(int i = 1;i <= n;i ++ ){
    cin >> p;
    --p;
    upd(p);
    inv += ask(p + 1, n - 1);
  }
  inv %= 2;
  if(inv == (n * 3) % 2){
    cout << "Petr\n";
  }
  else{
    cout << "Um_nik\n";
  }
  return 0;
}