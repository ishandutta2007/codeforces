#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int t[N];
int cnt[N];
long long add[N];
long long sum[N];

int main(){
	
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", t + i);
    sum[i] = t[i] + sum[i - 1];
  }

  for(int i = 1; i <= n; ++i){
    int it = lower_bound(sum + i, sum + n + 1, sum[i - 1] + a[i]) - sum;


    add[it] += a[i] - (sum[it - 1] - sum[i - 1]);

    cnt[i]++;
    cnt[it]--;
  }

  for(int i = 1; i <= n; ++i){
    cnt[i] += cnt[i - 1];
    printf("%lld ", 1LL * t[i] * cnt[i] + add[i]);
  }

	return 0;
}