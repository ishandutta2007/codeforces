#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  set<int>uniq;
  int arr[n];
  for(int i = 0;i<n;i++)
    cin >> arr[i];
  sort(arr,arr+n);
  int s = 0;
  for(int i = 1;i<=n;i++){
    for(int j = n-i;j>=0;j--){
      if(!uniq.count(s+arr[j])){
        if(k==0)continue;
        uniq.insert(s+arr[j]);
        cout << i << " ";
        for(int x = 1;x<i;x++)
          cout << arr[n-x] << " ";
        cout << arr[j] << "\n";
        --k;
      }
    }
    s+=arr[n-i];
  }
  return 0;
}