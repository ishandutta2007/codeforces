#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  int el[n+1];
  el[n] = 2e9;
  for(int i = 0;i<n;i++)
    cin >> el[i];
  sort(el,el+n+1);
  int cnt = 0;
  for(int j = 0;j<n;j++){
    cnt++;
    if(el[j]!=el[j+1]){
      if(k>1LL*cnt*n)k-=1LL*cnt*n;
      else{
        cout << el[j] << " ";
        for(int v = 0;v<n;v++){
          k-=cnt;
          if(k<=0){
            cout << el[v] << "\n";
            exit(0);
          }
        }
        exit(0);
      }
      cnt=0;
    } 
  }
  return 0;
}