#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
bool good[N];
int a[N];

void solve(){
  int n, m;
  cin >> n >> m;
  int x;
  for(int i = 1; i <= n ; i ++ ){
    cin >> a[i];
    good[i]=false;
  }
  for(int i = 1; i <= m ; i ++ ){
    cin >> x;
    good[x]=true;
  }
  int lf = 1;
  int rf;
  while(lf < n){
    if(!good[lf]){
      lf ++ ;
      continue;
    }
    rf = lf + 1;
    while(good[rf])
      rf++;
    sort(a + lf, a + rf + 1);
    lf=rf;
  }
  for(int i = 1; i < n ; i ++ ){
    if(a[i] > a[i + 1]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc;t ++ ){
    solve();
  }
  return 0;
}