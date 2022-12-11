#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
bool has[N];

int main(){ 
  fastIO;
  int n;
  cin >> n;
  int a;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    has[a] = true;
  }
  bool ok;
  int res = 0;
  for(int i = 1; i < N ; i ++ ){
    if(has[i]){
      res ++ ;
      for(int j = i ; j < N ; j += i ){
        has[j] = false;
      }
    }
  }
  cout << res;
  return 0;
}