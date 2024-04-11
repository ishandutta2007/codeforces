#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 31;
int cnt[LOG];

int main(){
  fastIO;
  int n;
  cin >> n;
  int a[n];
  for(int i = 0 ; i < n; i ++ ){
    cin >> a[i];
    for(int j = 0 ; j < LOG; j ++ )
      if(a[i] & (1 << j))
        cnt[j] ++ ;
  }
  int res = -1,id=-1 ;
  int cur;
  for(int i = 0 ; i < n ; i ++ ){
    cur = 0;
    for(int j = 0 ; j < LOG; j ++ ){
      if(a[i] & (1 << j)){
        if(cnt[j] == 1) cur |= (1 << j);
      }
    }
    if(cur > res){
      res = cur;
      id = i;
    }
  }
  cout << a[id] << " ";
  for(int i = 0 ; i < n ; i ++ ){
    if(i != id) cout << a[i] << " ";
  }
  cout << "\n";
  return 0;
}