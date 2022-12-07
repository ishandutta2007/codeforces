#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n;
string arr[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif // pts
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  //cout.tie(NULL);
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> arr[i];
  }
  for(int i = n - 1; i >= 1; --i){
    int pos = 0;
    while(pos < arr[i].size() && pos < arr[i + 1].size()){
      if(arr[i][pos] != arr[i + 1][pos]){
        break;
      }
      ++pos;
    }
    if(pos == arr[i + 1].size()){
      arr[i] = arr[i].substr(0, pos);
      continue;
    }
    if(pos == arr[i].size()){
      continue;
    }
    if(arr[i][pos] < arr[i + 1][pos]){
      continue;
    }
    arr[i] = arr[i].substr(0, pos);
  }
  for(int i = 1; i <= n; ++i){
    cout << arr[i] << endl;
  }
  return 0;
}