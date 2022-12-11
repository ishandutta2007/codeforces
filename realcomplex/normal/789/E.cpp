#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
const int K = 1000;
bool can[N];
int dis[N];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  int q;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> q;
    can[q-n+K] = true;
  }
  queue<int> f;
  for(int j = 0 ; j < N; j ++ ){
    dis[j] = (int)1e9;
  }
  dis[K]=0;
  f.push(K);
  int nd;
  int sm;
  while(!f.empty()){
    nd = f.front();
    f.pop();
    for(int j = 0 ; j < N ; j ++ ){
      if(can[j]){
        sm = nd + (j - K);
        if(sm == K){
          cout << dis[nd] + 1 << "\n";
          return 0;
        }
        if(sm >= 0 && sm < N && dis[sm] == (int)1e9){
          f.push(sm);
          dis[sm] = dis[nd] + 1;
        }
      }
    }
  }
  cout << -1;
  return 0;
}