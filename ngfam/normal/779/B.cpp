#include <bits/stdc++.h>

using namespace std;

char a[111];
int k, cnt;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "W", stdout);
  #endif // pts
  scanf("%s%d", a + 1, &k);
  int n = strlen(a + 1);
  for(int i = n; i >= 1; --i){
    if(a[i] == '0'){
      ++cnt;
    }
  }
  if(cnt < k){
    cout << n - 1;
    return 0;
  }
  int curr = 0, answer = 0;
  for(int i = n; i >= 1; --i){
    if(a[i] == '0'){
      curr++;
    }
    else{
      ++answer;
    }
    if(curr == k){
      break;
    }
  }
  cout << answer;
  return 0;
}