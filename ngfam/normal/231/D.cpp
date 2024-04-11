#include <bits/stdc++.h>

using namespace std;

int a[7];
int x, y, z;
int u, v, k;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d%d", &u, &v, &k);
  scanf("%d%d%d", &x, &y, &z);
  for(int i = 1; i <= 6; ++i){
    scanf("%d", a + i);
  }
  int answer = 0;
  if(v > y){
    answer += a[2];
  }
  if(v < 0){
    answer += a[1];
  }
  if(u > x){
    answer += a[6];
  }
  if(u < 0){
    answer += a[5];
  }
  if(k > z){
    answer += a[4];
  }
  if(k < 0){
    answer += a[3];
  }
  cout << answer;
  return 0;
}