#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, M = 65;

int n;
int arr[N];
int vrr[N];
int ok[M][M];
int f[M][M];

int calc(int u, int ban){
  if(u == 0){
    return 0;
  }
  if(ok[u][ban] == 1){
    return f[u][ban];
  }
  ok[u][ban] = 1;
  bool grundy[65];
  memset(grundy, 0, sizeof grundy);
  for(int i = 1; i <= min(u, ban); ++i){
    grundy[calc(u - i, i - 1)] = 1;
  }
  for(int i = 0; i <= 60; ++i){
    if(grundy[i] == 0){
      return f[u][ban] = i;
    }
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  for(int i = 1; i <= 60; ++i){
    vrr[i] = calc(i, 60);
/*    if(i <= 2){
      cerr << vrr[i] << endl;
    }*/
  }
  int answer = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int value;
    scanf("%d", &value);
    answer ^= vrr[value];
  }
  if(answer == 0){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
  return 0;
}