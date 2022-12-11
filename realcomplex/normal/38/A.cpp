#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int arr[n]; 
  for(int i = 0;i<n-1;i++)
    cin >> arr[i];
  int a,b;
  cin >> a >> b;
  --a;--b;
  int ans = 0;
  while(a<b){
    ans += arr[a];
    a++;
  }
  cout << ans << "\n";
  return 0;
}