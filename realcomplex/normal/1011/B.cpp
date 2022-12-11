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
#define ones(a) __builtin_popcount(a)

int n;
int cnt[105];

bool check(int l){
  if(l == 0)
    return false;
  int p = 0;
  for(int x = 1; x <= 100; x ++ )
    p += cnt[x] / l;
  return p >= n;
}

int main(){
  fastIO;
  int m;
  cin >> n >> m;
  int x;
  for(int i = 1;i <= m;i ++ ){
    cin >> x;
    cnt[x] ++ ;
  }
  int l = 0, r = m+1;
  int md;
  while(l + 1 < r){
    md = (l + r)/2;
    if(check(md)){
      l = md; 
    }
    else{
      r = md;
    }
  }
  cout << l;
  return 0;
}