#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int arr[N][N], ans[N][N], n, m, col[N], row[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		//freopen("1.out", "w", stdout);
	#endif
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= max(m, n); ++i) col[i] = row[i] = 1;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 0){
        col[j] = 0;
        row[i] = 0;
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int val = 1;
      for(int k = 1; k <= n; ++k){
        val = min(val, arr[k][j]);
      }
      for(int k = 1; k <= m; ++k){
        val = min(val, arr[i][k]);
      }
      ans[i][j] = val;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int val = 0;
      for(int k = 1; k <= n; ++k){
        val |= ans[k][j];
      }
      for(int k = 1; k <= m; ++k){
        val |= ans[i][k];
      }
      if(val != arr[i][j]){
        puts("NO");
        return 0;
      }
    }
  }

  puts("YES");
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      printf("%d ", ans[i][j]);
    }
    puts("");
  }
	return 0;
}