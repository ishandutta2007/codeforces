#include <bits/stdc++.h>

using namespace std;

const int N = 100010;


int n;
int f[N];
int cnt[N];


int main(){
	 

  scanf("%d", &n);
  for(int i = 2; i <= n; ++i){
    int v;
    scanf("%d", &v);
    ++cnt[f[i] = f[v] + 1];
  }

  int ans = 1;


  for(int i = 0; i <= n; ++i){
    ans += cnt[i] % 2;
  }

  cout << ans;

	return 0;
}