#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%i",&n);
  int arr[n];
  int cnt = 0;
  for(int j = 0;j<n;j++){
    scanf("%i",&arr[j]);
    cnt += (arr[j]==1);
  }
  if(cnt>0){cout << n-cnt << "\n";return 0;}
  int k;
  int ans = INT_MAX;
  for(int j = 0;j<n;j++){
    k = arr[j];
    for(int i = j;i<n;i++){
      k = __gcd(k,arr[i]);
      if(k==1)
        ans = min(ans,(i-j)+(n-1));
    }
  }
  cout << ((ans==INT_MAX) ? -1 : ans);
  return 0;
}