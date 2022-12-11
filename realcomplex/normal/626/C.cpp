#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int v1 = 0, v2 = 0, v3 = 0;
  int p = 1;
  bool ok = false;
  while(!ok){
    v1 = p/2;
    v2 = p/3;
    v3 = (p/2) + (p/3) - (p/6);
    if(v3 >= n + m and v1 >= n and v2 >= m){
      cout << p;
      return 0;
    }
    p ++ ;
  }
  return 0;
}