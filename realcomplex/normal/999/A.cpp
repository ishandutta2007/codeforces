#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  int d[n];
  bool is = true;
  for(int i = 0;i < n;i ++ ){
    cin >> d[i];
    if(d[i] > k)
      is = false;
  }
  if(is){
    cout << n;
    return 0;
  }
  int ans = 0;
  for(int i = 0;i < n;i ++ ){
    if(d[i] > k)
      break;
    ans ++ ;
  }
  for(int i = n-1;i >= 0;i -- ){
    if(d[i] > k)
      break;
    ans ++ ;
  }
  cout << ans;
  return 0;
}