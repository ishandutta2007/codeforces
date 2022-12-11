#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int n,x;
  cin >> n >> x;
  int req[n];
  for(int i = 0;i<n;i++){
    cin >> req[i];
    req[i]*=n-i;
  }
  sort(req,req+n);
  int ans = 0; 
  for(int i = 0;i<n;i++){
    if(req[i]<=x){
      ans++;
      x-=req[i];
    }
  }
  cout << ans << "\n";
  return 0;
}