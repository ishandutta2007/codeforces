#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n,d;
  cin >> n >> d;
  int arr[n];
  for(int i = 0;i < n;i ++ ){
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = (int)1e9;
  int cnt = 0;
  for(int i = 0;i < n;i ++){
    cnt = 0;
    for(int j = i;j < n;j ++ ){
      cnt++;
      if(arr[j] - arr[i] > d)
        break;
      ans = min(ans, n - cnt);
    }
  }
  cout << ans;
  return 0;
}