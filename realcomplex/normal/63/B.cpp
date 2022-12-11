#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  scanf("%i %i",&n,&k);
  int ans = 0;
  int arr[n];
  for(int i = 0;i<n;i++)
    scanf("%i",&arr[i]);
  for(int j = n-1;j>=0;j--){
    while(arr[j]<k){
      ans++;
      for(int i = j-1;i>=0;i--){
        if(arr[i]!=arr[i+1])
          arr[i]++;
      }
      arr[j]++;
    }
  }
  printf("%i\n",ans);
  return 0;
}