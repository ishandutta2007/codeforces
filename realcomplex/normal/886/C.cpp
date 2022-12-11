#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 9;
int cnt[N];
int main(){
  int n;
  scanf("%i",&n);
  int k;
  for(int i = 0;i<n;i++){
    scanf("%i",&k);
    cnt[k]++;
  }
  int ans = 1;
  for(int i = 0;i<n;i++)
    ans += max(0,cnt[i]-1);
  printf("%i\n",ans);
  return 0;
}