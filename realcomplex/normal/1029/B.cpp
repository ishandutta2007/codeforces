#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

int main(){
  fastIO;
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n;i ++ )
    cin >> a[i];
  int ans = 1;
  int cnt = 1;
  for(int i = 1;i < n;i ++ ){
    if(a[i - 1] * 2 >= a[i]){
      cnt ++ ;
      ans = max(ans, cnt);
    }
    else{
      cnt = 1;
    }
  }
  cout << ans;
  return 0;
}