#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int per[N];
int pos[N];
int cnt[N];
int nx[N];
bool ban[N];

void solve(){
  int n;
  cin >> n;
  cnt[n + 1] = 0;
  nx[n + 1] = n + 1;
  for(int i = 1; i <= n; i ++ ){
    cin >> per[i];
    pos[per[i]] = i;
    cnt[i] = 1;
    nx[i] = i;
    ban[i] = false;
  }
  int p;
  priority_queue<pii> ff;
  for(int i = 1; i <= n; i ++ )
    ff.push(mp(1,i));
  for(int i = 1; i <= n; i ++ ){
    p = pos[i];
    while(ban[ff.top().se]){
      ff.pop();
    }
    if(cnt[p] == ff.top().fi){
      p ++ ;
      while(nx[p] != p) p = nx[p];
      cnt[p] ++ ;
      if(p != n + 1)ff.push(mp(cnt[p], p));
      nx[pos[i]] = p;
    }
    else{
      cout << "No\n";
      return;
    }
    ban[pos[i]] = true;
  }
  cout << "Yes\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    solve();
  }
  return 0;
}