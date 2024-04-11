#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int a[N];
int lf[N];
int rf[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    lf[i]=1;
    rf[i]=1;
  }
  for(int i = 2; i <= n; i ++ ){
    if(a[i] > a[i - 1])
      lf[i]=lf[i-1]+1;
  }
  for(int i = n - 1; i >= 1; i -- ){
    if(a[i] < a[i + 1])
      rf[i]=rf[i+1]+1;
  }
  int ans = 0;
  for(int i = 1; i <= n; i ++ ) 
    ans = max(ans, lf[i]);
  for(int i = 1; i <= n - 2; i ++ ){
    if(a[i] < a[i + 2]){
      ans = max(ans, lf[i] + rf[i + 2]);
    }
  }
  cout << ans;
  return 0;
}