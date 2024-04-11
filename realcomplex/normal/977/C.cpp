#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  int arr[n + 1];
  for(int i = 1; i <= n;i ++ ){
    cin >> arr[i];
  }
  if(k == n){
    cout << (int)1e9;
    return 0;
  }
  arr[0] = 0;
  sort(arr,arr + n + 1);
  if(k == 0){
    if(arr[1] == 1) cout << -1;
    else cout << 1;
    return 0;
  }
  for(int i = 0;i < n; i ++ ){
    if(arr[i] != arr[i + 1]){
      if(i == k){
        cout << arr[i] << "\n";
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}