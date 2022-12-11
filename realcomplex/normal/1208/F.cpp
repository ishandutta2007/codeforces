#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
const int M = (1<<21);
int a[N];
int best[M][2];

void add(int i, int pos){
  if(best[i][0] == -1)
    best[i][0] = pos;
  else{
    if(best[i][0] < pos){
      best[i][1] = best[i][0];
      best[i][0] = pos;
      return;
    }
    if(best[i][0] == pos) return;
    if(best[i][1] == -1){
      best[i][1] = pos;
    }
    if(best[i][1] < pos){
      best[i][1] = pos;
    }
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
  }
  for(int i = 0 ; i < M ; i ++ ){
    best[i][0] = -1;
    best[i][1] = -1;
  }
  for(int i = 1; i <= n; i ++ ){
    add(a[i], i);
  }
  int mask;
  for(int i = M - 1; i >= 0 ; i -- ){
    for(int j = 0 ; j < 21; j ++ ){
      if(i & (1 << j)){
        mask = (i ^ (1 << j));
        if(best[i][0] != -1)add(mask, best[i][0]);
        if(best[i][1] != -1)add(mask, best[i][1]);
      }
    }
  }
  int ret = 0;
  int cur;
  for(int i = 1; i <= n-2; i ++ ){
    mask = a[i];
    cur = 0;
    for(int j = 20 ; j >= 0 ; j -- ){
      if(mask & (1 << j)){
        continue;
      }
      if(best[cur | (1 << j)][0] > i && best[cur | (1 << j)][1] > i){
        cur |= (1 << j);
      }
    }
    ret = max(ret, mask + cur);
  }
  cout << ret << "\n";
  return 0;
}