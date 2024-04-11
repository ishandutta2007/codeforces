#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  int a[n];
  char v;
  for(int i = 0 ;i < n;i ++ ){
    cin >> v;
    a[i] = v - 'a' + 1;
  }
  sort(a, a + n);
  int las = -1;
  int sum = 0;
  for(int i = 0;i < n;i ++ ){
    if(a[i] - las > 1){
      sum += a[i];
      las = a[i];
      k -- ;
      if(k == 0){
        cout << sum;
        return 0;
      }
    } 
  }
  cout << -1;
  return 0;
}