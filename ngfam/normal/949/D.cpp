#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, b, d;
int a[N];
int f[N];
int sumPref[N];

int main(){

  scanf("%d%d%d", &n, &d, &b);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    sumPref[i] = sumPref[i - 1] + a[i];
  }

  int low = 0, high = (n + 1) / 2 - 1, ans = high + 1;

  while(low <= high){
    int mid = (low + high) >> 1;

    int fail = 0, middle = 0;
    for(int i = 1; i * 2 <= n + 1; ++i){
      if(i <= mid) continue;
      int r = min(1LL * n, 1LL * (i) * (d + 1));
      if(sumPref[r] < (i - mid) * b)  fail = 1;
    }

    for(int i = n; i * 2 > n + 1; --i){
      if(i > n - mid) continue;
      int r = max(0LL, i - 1LL * (n - i + 1) * d - 1);
      if(sumPref[n] - sumPref[r] < (n - mid - i + 1) * b && (i * 2 - 1 != n || !middle))  fail = 1;
    }

    if(fail == 0){
      ans = mid;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }

  cout << ans;

	return 0;
}