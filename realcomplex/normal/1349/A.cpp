#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

int dc[N];
vector<int> di[N];

int main(){
  fastIO;
  for(int i = 1; i < N ; i ++ ){
    for(int j = i; j < N ; j += i ){
      di[j].push_back(i);
    }
  }
  int n;
  cin >> n;
  int x;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> x;
    for(auto y : di[x]){
      dc[y]++;
    }
  }
  ll ans = 1;
  int p;
  for(int i = 2; i < N ; i ++ ){
    if(di[i].size() != 2) continue;
    p=i;
    while(p < N && dc[p] >= n - 1){
      ans = (ans * 1ll * i);
      p *= i;
    }
  }
  cout << ans << "\n";
  return 0;
}