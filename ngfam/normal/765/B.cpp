#include <bits/stdc++.h>

using namespace std;

string arr;
int last[155];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  cin >> arr;
  for(int i = 0; i < arr.size(); ++i){
    if(last[arr[i]] != 0) continue;
    last[arr[i]] = i + 1;
  }
  for(int i = 'a'; i <= 'z'; ++i){
    if(last[i] == 0){
      last[i] = arr.size() + 5;
    }
  }

  for(int i = 'a'; i < 'z'; ++i){
    if(last[i] > last[i + 1]){
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}